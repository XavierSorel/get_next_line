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
	//printf("im in ft_lstnew\n");
	t_list	*new_node;
	int	i;

	i = 0;
	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	while (content[i])
	{
		new_node->content[i] = content[i];
		i++;
	}
	new_node->next = NULL;
	return (new_node);
}

void    ft_lstadd_back(t_list **lst, t_list *new)
{
        //printf("im in lstadd_back Start\n");
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
	//printf("im in lstadd_back End\n");
}

int	size_return_str(t_list *lst)
{
	t_list	*current;
	size_t	size;

	size = 0;
	current = lst;
	while (current)
	{
		size += ft_strlen(current->content);
		current = current->next;
	}
	return (size);
}

void	ft_merge_lst_return(t_list **lst, char **full_line)
{
	//printf("im in merge lst\n");
	char 	*start;
	t_list	*current;
	int	i;
	size_t	len;
	
	len = size_return_str(*lst);
	*full_line = (char *)malloc(sizeof(char) * len + 1);
	start = *full_line;
	current = *lst; 
	while (current)
	{
		i = 0;
		while (current->content[i] != '\0')
		{
			*start = current->content[i];
			i++;
			start++;
		}
		current = current->next;
	}
	*start = '\0';
}

int 	ft_strrchr(const char *str)
{
	//printf("im in strrchr\n");
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\0' || str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
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

void	free_all(t_list **lst)
{
	//printf("im in free all\n");
        t_list  *current;
        t_list  *to_delete;

        if (!lst)
                return ;
        current = *lst;
        while (current)
        {
                        to_delete = current;
                        current = current->next;
                        //free(to_delete->content);
                        free(to_delete);
        }
        *lst = NULL;
}

