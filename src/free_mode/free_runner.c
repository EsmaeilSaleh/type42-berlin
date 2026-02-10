#include "free_runner.h"
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define PATH_BUF_SIZE 512

static int ensure_dir(const char *path)
{
    if (mkdir(path, 0755) == 0)
        return (0);
    if (errno == EEXIST)
        return (0);
    return (-1);
}

static int contains_main_declaration(const char *s)
{
    if (!s)
        return (0);
    if (strstr(s, "main(") != NULL)
        return (1);
    if (strstr(s, "main (") != NULL)
        return (1);
    return (0);
}

static void write_output_snippet(const char *path, char *output, size_t output_size)
{
    int fd;
    ssize_t n;

    if (!output || output_size == 0)
        return;
    output[0] = '\0';
    fd = open(path, O_RDONLY);
    if (fd < 0)
        return;
    n = read(fd, output, output_size - 1);
    if (n > 0)
        output[n] = '\0';
    close(fd);
}

static int run_command_capture(char *const argv[], const char *output_path,
                               int timeout_sec, int *timed_out)
{
    int fd;
    pid_t pid;
    int status;
    int elapsed_ms;

    fd = open(output_path, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd < 0)
        return (-1);
    pid = fork();
    if (pid < 0)
    {
        close(fd);
        return (-1);
    }
    if (pid == 0)
    {
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        close(fd);
        execvp(argv[0], argv);
        _exit(127);
    }
    close(fd);
    if (timed_out)
        *timed_out = 0;
    if (timeout_sec <= 0)
    {
        if (waitpid(pid, &status, 0) < 0)
            return (-1);
        return (status);
    }
    elapsed_ms = 0;
    while (1)
    {
        pid_t rv;

        rv = waitpid(pid, &status, WNOHANG);
        if (rv == pid)
            return (status);
        if (rv < 0)
            return (-1);
        if (elapsed_ms >= timeout_sec * 1000)
        {
            kill(pid, SIGKILL);
            waitpid(pid, &status, 0);
            if (timed_out)
                *timed_out = 1;
            return (status);
        }
        usleep(10000);
        elapsed_ms += 10;
    }
}

static int is_supported_char_func(const char *func_name)
{
    if (strcmp(func_name, "ft_isalpha") == 0)
        return (1);
    if (strcmp(func_name, "ft_isdigit") == 0)
        return (1);
    if (strcmp(func_name, "ft_isalnum") == 0)
        return (1);
    if (strcmp(func_name, "ft_isascii") == 0)
        return (1);
    if (strcmp(func_name, "ft_isprint") == 0)
        return (1);
    if (strcmp(func_name, "ft_toupper") == 0)
        return (1);
    if (strcmp(func_name, "ft_tolower") == 0)
        return (1);
    return (0);
}

static int file_has_real_newline(const char *path)
{
    int fd;
    char buf[256];
    ssize_t n;
    ssize_t i;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (0);
    n = read(fd, buf, sizeof(buf));
    close(fd);
    if (n <= 0)
        return (0);
    i = 0;
    while (i < n)
    {
        if (buf[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

static int write_bool_case(FILE *fp, const char *func_name, const char *libc_name, int cast_expected)
{
    if (!fp)
        return (-1);
    fprintf(fp, "    for (i = 0; i <= 255; i++)\n");
    fprintf(fp, "    {\n");
    if (cast_expected)
        fprintf(fp, "        expected = (%s((unsigned char)i) != 0);\n", libc_name);
    else
        fprintf(fp, "        expected = (%s(i) != 0);\n", libc_name);
    fprintf(fp, "        got = (%s(i) != 0);\n", func_name);
    fprintf(fp, "        if (got != expected)\n");
    fprintf(fp, "        {\n");
    fprintf(fp, "            printf(\"FAIL %s: input=%%d expected=%%d got=%%d\\n\", i, expected, got);\n", func_name);
    fprintf(fp, "            return (1);\n");
    fprintf(fp, "        }\n");
    fprintf(fp, "    }\n");

    fprintf(fp, "    extras[0] = -1;\n");
    fprintf(fp, "    extras[1] = 256;\n");
    fprintf(fp, "    extras[2] = 1000;\n");
    fprintf(fp, "    for (j = 0; j < 3; j++)\n");
    fprintf(fp, "    {\n");
    if (cast_expected)
        fprintf(fp, "        expected = (%s((unsigned char)extras[j]) != 0);\n", libc_name);
    else
        fprintf(fp, "        expected = (%s(extras[j]) != 0);\n", libc_name);
    fprintf(fp, "        got = (%s(extras[j]) != 0);\n", func_name);
    fprintf(fp, "        if (got != expected)\n");
    fprintf(fp, "        {\n");
    fprintf(fp, "            printf(\"FAIL %s: input=%%d expected=%%d got=%%d\\n\", extras[j], expected, got);\n", func_name);
    fprintf(fp, "            return (1);\n");
    fprintf(fp, "        }\n");
    fprintf(fp, "    }\n");
    return (0);
}

static int write_int_case(FILE *fp, const char *func_name, const char *libc_name)
{
    if (!fp)
        return (-1);
    fprintf(fp, "    for (i = 0; i <= 255; i++)\n");
    fprintf(fp, "    {\n");
    fprintf(fp, "        expected = %s((unsigned char)i);\n", libc_name);
    fprintf(fp, "        got = %s(i);\n", func_name);
    fprintf(fp, "        if (got != expected)\n");
    fprintf(fp, "        {\n");
    fprintf(fp, "            printf(\"FAIL %s: input=%%d expected=%%d got=%%d\\n\", i, expected, got);\n", func_name);
    fprintf(fp, "            return (1);\n");
    fprintf(fp, "        }\n");
    fprintf(fp, "    }\n");

    fprintf(fp, "    extras[0] = -1;\n");
    fprintf(fp, "    extras[1] = 256;\n");
    fprintf(fp, "    extras[2] = 1000;\n");
    fprintf(fp, "    for (j = 0; j < 3; j++)\n");
    fprintf(fp, "    {\n");
    fprintf(fp, "        expected = %s((unsigned char)extras[j]);\n", libc_name);
    fprintf(fp, "        got = %s(extras[j]);\n", func_name);
    fprintf(fp, "        if (got != expected)\n");
    fprintf(fp, "        {\n");
    fprintf(fp, "            printf(\"FAIL %s: input=%%d expected=%%d got=%%d\\n\", extras[j], expected, got);\n", func_name);
    fprintf(fp, "            return (1);\n");
    fprintf(fp, "        }\n");
    fprintf(fp, "    }\n");
    return (0);
}

int write_user_code_file(const char *func_name, const char *typed_text,
                         char *out_path, size_t out_path_size,
                         char *err, size_t err_size)
{
    FILE *fp;

    if (!func_name || !typed_text)
        return (-1);
    if (contains_main_declaration(typed_text))
    {
        snprintf(err, err_size, "Detected 'main'. Free Mode expects function-only input.");
        return (-1);
    }
    if (ensure_dir("typed") < 0)
    {
        snprintf(err, err_size, "Failed to create typed/ directory.");
        return (-1);
    }
    snprintf(out_path, out_path_size, "typed/%s_user.c", func_name);
    fp = fopen(out_path, "w");
    if (!fp)
    {
        snprintf(err, err_size, "Failed to open %s", out_path);
        return (-1);
    }
    fprintf(fp, "#include <stddef.h>\n#include <stdlib.h>\n#include <unistd.h>\n#include <ctype.h>\n\n");
    fprintf(fp, "%s", typed_text);
    if (typed_text[0] != '\0' && typed_text[strlen(typed_text) - 1] != '\n')
        fprintf(fp, "\n");
    fclose(fp);
    if (!file_has_real_newline(out_path))
    {
        snprintf(err, err_size, "Generated user file has invalid newlines.");
        return (-1);
    }
    return (0);
}

int write_test_harness(const char *func_name,
                       char *out_path, size_t out_path_size,
                       char *err, size_t err_size)
{
    FILE *fp;

    if (!func_name)
        return (-1);
    if (!is_supported_char_func(func_name))
    {
        snprintf(err, err_size, "No Free Mode harness for %s yet.", func_name);
        return (-1);
    }
    if (ensure_dir("build") < 0)
    {
        snprintf(err, err_size, "Failed to create build/ directory.");
        return (-1);
    }
    snprintf(out_path, out_path_size, "build/free_test_%s.c", func_name);
    fp = fopen(out_path, "w");
    if (!fp)
    {
        snprintf(err, err_size, "Failed to open %s", out_path);
        return (-1);
    }

    fprintf(fp, "#include <stdio.h>\n");
    fprintf(fp, "#include <ctype.h>\n\n");
    fprintf(fp, "int %s(int c);\n\n", func_name);
    fprintf(fp, "int main(void)\n");
    fprintf(fp, "{\n");
    fprintf(fp, "    int i;\n");
    fprintf(fp, "    int j;\n");
    fprintf(fp, "    int expected;\n");
    fprintf(fp, "    int got;\n");
    fprintf(fp, "    int extras[3];\n\n");

    if (strcmp(func_name, "ft_isalpha") == 0)
        write_bool_case(fp, func_name, "isalpha", 1);
    else if (strcmp(func_name, "ft_isdigit") == 0)
        write_bool_case(fp, func_name, "isdigit", 1);
    else if (strcmp(func_name, "ft_isalnum") == 0)
        write_bool_case(fp, func_name, "isalnum", 1);
    else if (strcmp(func_name, "ft_isascii") == 0)
        write_bool_case(fp, func_name, "isascii", 0);
    else if (strcmp(func_name, "ft_isprint") == 0)
        write_bool_case(fp, func_name, "isprint", 1);
    else if (strcmp(func_name, "ft_toupper") == 0)
        write_int_case(fp, func_name, "toupper");
    else if (strcmp(func_name, "ft_tolower") == 0)
        write_int_case(fp, func_name, "tolower");

    fprintf(fp, "    printf(\"OK\\n\");\n");
    fprintf(fp, "    return (0);\n");
    fprintf(fp, "}\n");
    fclose(fp);
    if (!file_has_real_newline(out_path))
    {
        snprintf(err, err_size, "Generated harness file has invalid newlines.");
        return (-1);
    }
    return (0);
}

int compile_harness(const char *func_name,
                    const char *user_path,
                    const char *harness_path,
                    char *bin_path, size_t bin_path_size,
                    char *output, size_t output_size)
{
    char log_path[PATH_BUF_SIZE];
    char *argv[9];
    int status;

    (void)func_name;
    snprintf(bin_path, bin_path_size, "build/free_test_%s", func_name);
    snprintf(log_path, sizeof(log_path), "build/free_compile_%s.log", func_name);

    argv[0] = "cc";
    argv[1] = "-Wall";
    argv[2] = "-Wextra";
    argv[3] = "-Werror";
    argv[4] = (char *)user_path;
    argv[5] = (char *)harness_path;
    argv[6] = "-o";
    argv[7] = bin_path;
    argv[8] = NULL;

    status = run_command_capture(argv, log_path, 0, NULL);
    write_output_snippet(log_path, output, output_size);

    if (status < 0)
        return (-1);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
        return (1);
    return (0);
}

int run_tests(const char *func_name,
              const char *bin_path,
              int timeout_sec,
              char *output, size_t output_size)
{
    char log_path[PATH_BUF_SIZE];
    char *argv[2];
    int status;
    int timed_out;

    snprintf(log_path, sizeof(log_path), "build/free_run_%s.log", func_name);
    argv[0] = (char *)bin_path;
    argv[1] = NULL;

    status = run_command_capture(argv, log_path, timeout_sec, &timed_out);
    write_output_snippet(log_path, output, output_size);

    if (timed_out)
    {
        snprintf(output, output_size, "FAIL %s: timeout after %d seconds", func_name, timeout_sec);
        return (1);
    }
    if (status < 0)
        return (-1);
    if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
        return (1);
    return (0);
}

int free_mode_compile_and_test(const char *func_name,
                               const char *typed_text,
                               char *output, size_t output_size)
{
    char user_path[PATH_BUF_SIZE];
    char harness_path[PATH_BUF_SIZE];
    char bin_path[PATH_BUF_SIZE];
    char err[256];
    int rc;

    if (!output || output_size == 0)
        return (FREE_RUNNER_ERROR);
    output[0] = '\0';
    err[0] = '\0';

    rc = write_user_code_file(func_name, typed_text, user_path, sizeof(user_path), err, sizeof(err));
    if (rc < 0)
    {
        snprintf(output, output_size, "%s", err[0] ? err : "Unable to write user code file.");
        return (FREE_RUNNER_ERROR);
    }

    rc = write_test_harness(func_name, harness_path, sizeof(harness_path), err, sizeof(err));
    if (rc < 0)
    {
        snprintf(output, output_size, "%s", err[0] ? err : "Unable to write test harness.");
        return (FREE_RUNNER_ERROR);
    }

    rc = compile_harness(func_name, user_path, harness_path, bin_path, sizeof(bin_path), output, output_size);
    if (rc < 0)
        return (FREE_RUNNER_ERROR);
    if (rc != 0)
        return (FREE_RUNNER_COMPILE_ERROR);

    rc = run_tests(func_name, bin_path, 2, output, output_size);
    if (rc < 0)
        return (FREE_RUNNER_ERROR);
    if (rc != 0)
        return (FREE_RUNNER_FAIL);

    if (output[0] == '\0')
        snprintf(output, output_size, "OK");
    return (FREE_RUNNER_OK);
}
