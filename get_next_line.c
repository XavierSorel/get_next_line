/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xanglada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:04:15 by xanglada          #+#    #+#             */
/*   Updated: 2025/06/17 12:12:26 by xanglada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{
		static char	buffer[BUFFER_SIZE + 1];
		int			i;

		i = 0;
		read(fd, buffer, BUFFER_SIZE);
		return (buffer);
}

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
		return (1);
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
