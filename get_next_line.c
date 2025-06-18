/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xanglada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:04:15 by xanglada          #+#    #+#             */
/*   Updated: 2025/06/17 14:47:28 by xanglada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	static char		leftover[BUFFER_SIZE + 1];
	char			buffer[BUFFER_SIZE + 1];
	t_list			*new_line;
	t_list			*new_node;
	char 			*line_full;
	int 			i;

	read(fd, buffer, BUFFER_SIZE);
	while ((line_full = ft_strchr(buffer)) == NULL)
	{
		new_node = ft_lstnew(buffer);
		ft_lstadd_back(*new_line, new_node);
		read(fd, buffer, BUFFER_SIZE);
	}
	i = 0;
	while (buffer[i++] != "\0" && buffer[i++] != "\n")
	       leftover[i] = buffer[i];
	new_node = ft_lstnew(leftover);
	ft_lstadd_back(*new_node, new_node)	
	while (*line_full)
	{
		*leftover = *linefull;
		leftover++;
		linefull++;
	}
	return (XXXX);
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
