#include "get_next_line.h"
#include <assert.h>

int     main()
{
        int             fd;
       	char    	*line;

	fd = open("test.txt", O_RDONLY);
        if(fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
        	printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

