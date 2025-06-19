/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xanglada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:12:47 by xanglada          #+#    #+#             */
/*   Updated: 2025/06/17 14:46:35 by xanglada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstnew(char *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        t_list  *current;

        if (!new)
                return ;
        if (*lst == NULL)
        {
                *lst = new;
                new->next = NULL;
                return ;
        }
        current = *lst;
        while (current->next != NULL)
        {
                current = current->next;
        }
        current->next = new;
}

char	*ft_merge_lst_return(t_list **lst, size_t len)
{
	char	*full_line;
	char 	*start;
	t_list	*current;
	int	i;
	
	full_line = malloc((char *)sizeof(BUFFER_SIZE) * len);
	start = full_line;
	current = *lst; 
	while (current)
	{
		i = 0;
		while (current->content)
		{
			*full_line = current->content[i];
			i++;
			full_line++;
		}
		current = current->next;

	}
	return (start);
}


char	*ft_strchr(const char *str)
{
	while (*str)
	{
		if (*str == '\0' || *str == '\n')
			return ((char *)str);
		str++;
	}
	return (NULL);
}
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	free_all(char **ret_str)
{
	int	i;

	i = 0;
	while (ret_str[i])
	{
		free(ret_str[i]);
		i++;
	}
	free(ret_str);
}
