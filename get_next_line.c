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

void	print_buffer(char buffer[BUFFER_SIZE + 1])
{
	printf("Buffer content: %s\n", buffer);
}

char 	*get_next_line(int fd)
{
	static char		*leftover;
	char			*end_of_line;
	char			*full_line;
	char			buffer[BUFFER_SIZE + 1];
	t_list			*new_line;
	t_list			*new_node;
	int 			i;
	int			index_efol;
	int			len;
	
	printf("im get next line \n");
	len = 0;
	new_line = NULL;
	full_line = NULL;
	// Checks if there is leftover from earlier calls
	// and adds to start of list
	if (leftover != NULL)
	{
		new_node = ft_lstnew(leftover);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&new_line, new_node);
		len++;
	}
	leftover = NULL;
	read(fd, buffer, BUFFER_SIZE); //reads first buffer size chunk
	print_buffer(buffer);
	while ((index_efol = ft_strrchr(buffer)) == -1) 
	// calls func to check if EOL or EOF is in chunk
	// if its there returns position
	// otherwise enters loop to keep searching 
	{
		// Inside loop creates a node with the chunk of str
		// adds it a end of list 
		// reads another buffer size chunk
		printf("index_eol = %d \n", index_efol);
		len++;
		new_node = ft_lstnew(buffer);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&new_line, new_node);
		read(fd, buffer, BUFFER_SIZE);
		print_buffer(buffer);
	}
	end_of_line = (char *)malloc(sizeof(char) * (index_efol + 1));
	leftover = (char *)malloc(sizeof(char) * (BUFFER_SIZE - index_efol + 1));
	i = 0;
	// Puts remaining  chars before EOF/EOL for last node
	while (i < index_efol)
	{
	       end_of_line[i] = buffer[i];
	       i++;
	}
	 // Creates last node with the last chars
        new_node = ft_lstnew(end_of_line);
        ft_lstadd_back(&new_line, new_node);
	free(end_of_line);
	// Adds the remaining part of buffer to leftover
	// to be used on next call
	while (i < BUFFER_SIZE)
	{
		*leftover = buffer[i];
		i++;
		leftover++;
	}
	ft_merge_lst_return(&new_line, len, full_line);
	free_all(&new_line);
	printf("%s", full_line);
	return (full_line);
}
