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

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>

char *get_next_line(int fd)
{
	static char		*leftover;
	char			end_of_line[BUFFER_SIZE + 1];
	char			buffer[BUFFER_SIZE + 1];
	t_list			*new_line;
	t_list			*new_node;
	char 			*line_full;
	int 			i;

	// Checks if there is leftover from earlier calls
	// and adds to start of list
	if (leftover != NULL)
	{
		new_node = ft_lstnew(leftover);
		ft_lstadd_back(&new_line, new_node);
	}
	leftover = NULL;
	read(fd, buffer, BUFFER_SIZE); //reads first buffer size chunk
	while ((line_full = ft_strrchr(buffer)) == NULL) 
	// calls func to check if EOL or EOF is in chunk
	// if its NULL enters loop
	// otherwise assigns the buffer chunk to line_full and passes loop 
	{
		// Inside loop creates a node with the chunk of str
		// adds it a end of list 
		// reads another buffer size chunk
		new_node = ft_lstnew(buffer);
		ft_lstadd_back(&new_line, new_node);
		read(fd, buffer, BUFFER_SIZE);
	}
	i = 0;
	// puts remaining  chars before EOF/EOL for last node
	while (buffer[i] && buffer[i++] != '\n')
	       end_of_line[i] = buffer[i];
	// creates last node with the last chars
	new_node = ft_lstnew(end_of_line);
	ft_lstadd_back(&new_line, new_node);
	// Keeps adding whats left of buffer after EOL onto the static
	while (i < BUFFER_SIZE)
	{
		*leftover = buffer[i];
		*leftover++;
		i++;
	}
	free_all(new_line);
	return (ft_merge_lst_return(&new_line, len));
}

int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if(fd == -1)
	line = get_next_line(fd);
	printf("%s\n", line);
	return (0);
}
