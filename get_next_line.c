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
	
	new_line = NULL;
	full_line = NULL;
	if (leftover != NULL)
	{
		new_node = ft_lstnew(leftover);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&new_line, new_node);
		free(leftover);
	}
	leftover = NULL;
	read(fd, buffer, BUFFER_SIZE); 
	print_buffer(buffer);
	while ((index_efol = ft_strrchr(buffer)) == -1)  
	{
		printf("index_eol = %d \n", index_efol);
		new_node = ft_lstnew(buffer);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&new_line, new_node);
		read(fd, buffer, BUFFER_SIZE);
		//print_buffer(buffer);
	}
	end_of_line = (char *)malloc(sizeof(char) * (index_efol + 1));
	leftover = (char *)malloc(sizeof(char) * (BUFFER_SIZE - index_efol + 1));
	i = 0;
	while (i < index_efol)
	{
	       end_of_line[i] = buffer[i];
	       i++;
	}
	new_node = ft_lstnew(end_of_line);
        ft_lstadd_back(&new_line, new_node);
	free(end_of_line);
	while (i < BUFFER_SIZE)
	{
		*leftover = buffer[i];
		i++;
		leftover++;
	}
	ft_merge_lst_return(&new_line, &full_line);
	free_all(&new_line);
	printf("%s\n", full_line);
	return (full_line);
}
