#include "get_next_line.h"

int     main()
{
        int             fd;

        char    *line;

        fd = open("test.txt", O_RDONLY);
        if(fd == -1)
        line = get_next_line(fd);
        printf("%s\n", line);
        return (0);
}

