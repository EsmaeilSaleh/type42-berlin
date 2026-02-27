static int is_sep(char c)
{
    return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
    int start;
    int end;
    int i;
    int printed;

    if (argc == 2)
    {
        printed = 0;
        i = 0;
        while (is_sep(argv[1][i]))
            i++;
        start = i;
        while (argv[1][i] && !is_sep(argv[1][i]))
            i++;
        end = i;
        while (argv[1][i])
        {
            while (is_sep(argv[1][i]))
                i++;
            if (argv[1][i] && printed)
                write(1, " ", 1);
            if (argv[1][i])
                printed = 1;
            while (argv[1][i] && !is_sep(argv[1][i]))
                write(1, &argv[1][i++], 1);
        }
        if (end > start)
        {
            if (printed)
                write(1, " ", 1);
            write(1, &argv[1][start], end - start);
        }
    }
    write(1, "\n", 1);
    return (0);
}
