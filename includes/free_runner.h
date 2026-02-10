#ifndef FREE_RUNNER_H
#define FREE_RUNNER_H

#include <stddef.h>

#define FREE_RUNNER_OK 0
#define FREE_RUNNER_FAIL 1
#define FREE_RUNNER_COMPILE_ERROR 2
#define FREE_RUNNER_ERROR 3

int write_user_code_file(const char *func_name, const char *typed_text,
                         char *out_path, size_t out_path_size,
                         char *err, size_t err_size);

int write_test_harness(const char *func_name,
                       char *out_path, size_t out_path_size,
                       char *err, size_t err_size);

int compile_harness(const char *func_name,
                    const char *user_path,
                    const char *harness_path,
                    char *bin_path, size_t bin_path_size,
                    char *output, size_t output_size);

int run_tests(const char *func_name,
              const char *bin_path,
              int timeout_sec,
              char *output, size_t output_size);

int free_mode_compile_and_test(const char *func_name,
                               const char *typed_text,
                               char *output, size_t output_size);

#endif
