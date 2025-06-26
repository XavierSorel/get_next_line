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

/*void	print_buffer(char buffer[BUFFER_SIZE + 1])
{
	printf("Buffer content: %s\n", buffer);
}
*/
void	print_lst(t_list **lst)
{
	t_list	*current;
	int		i;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		i = 0;
		while (current->content[i])
			write(1, &current->content[i++], 1);
		current = current->next;
	}
}

void	add_leftover_newline(t_list **new_line, char *leftover)
{
	t_list	*new_node;

	printf("[DEBUG] Adding leftover: \"%s\"\n", leftover);
	new_node = ft_lstnew(leftover);
        if (!new_node)
		return ;
	ft_lstadd_back(new_line, new_node);
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
	if (leftover != NULL && leftover[0] != '\0')
		add_leftover_newline(&new_line, leftover);
	free(leftover);
	leftover = NULL;
	int bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0)
		return (NULL);
	if (bytes_read >= 0)
		buffer[bytes_read] = '\0';
	while ((index_efol = ft_strchr(buffer)) == -1)
	{
		new_node = ft_lstnew(buffer);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&new_line, new_node);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			return (NULL);
		if (bytes_read >= 0)
			buffer[bytes_read] = '\0';
	}
	end_of_line = (char *)malloc(sizeof(char) * (index_efol + 2));
	i = 0;
	while (i <= index_efol)
	{
	       end_of_line[i] = buffer[i];
	       i++;
	}
	new_node = ft_lstnew(end_of_line);
        ft_lstadd_back(&new_line, new_node);
	free(end_of_line);
	int	leftover_len = bytes_read - (index_efol + 1);
	if (leftover_len > 0)
	{        
		leftover = (char *)malloc(sizeof(char) * (leftover_len + 1));
		int a = 0;
		while (i < bytes_read)
			leftover[a++] = buffer[i++];
		leftover[a] = '\0';
	}
	else
		leftover = NULL;
	ft_merge_lst_return(&new_line, &full_line);
	printf("========== LINE BUILT ==========\n");
	print_lst(&new_line);
	printf("========= END OF LINE ==========\n");
	printf("Returned line: \"%s\"\n", full_line);

	free_all(&new_line);
	return (full_line);
}
