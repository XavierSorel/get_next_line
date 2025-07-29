/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xanglada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:04:15 by xanglada          #+#    #+#             */
/*   Updated: 2025/07/28 12:00:00 by xanglada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	t_list		*lst = NULL;
	char		*buf, *line, *tmp;
	int			r, eol;

	if (fd < 0 || BUFFER_SIZE <= 0 || !(buf = malloc(BUFFER_SIZE + 1)))
		return (NULL);
	if (leftover)
	{
		eol = find_eol(leftover);
		if (eol >= 0)
		{
			leftover[eol + 1] = '\0';
			line = gnl_strdup(leftover);
			tmp = gnl_strdup(leftover + eol + 1);
			free(leftover);
			leftover = tmp;
			free(buf);
			return (line);
		}
		lst = malloc(sizeof(t_list));
		if (!lst)
			return (free(buf), NULL);
		lst->content = leftover;
		lst->next = NULL;
		leftover = NULL;
	}
	while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[r] = '\0';
		eol = find_eol(buf);
		if (eol >= 0)
			buf[eol + 1] = '\0';
		t_list *new = malloc(sizeof(t_list));
		if (!new || !(new->content = gnl_strdup(buf)))
			return (free(buf), NULL);
		new->next = NULL;
		t_list **p = &lst;
		while (*p)
			p = &(*p)->next;
		*p = new;
		if (eol >= 0)
		{
			leftover = gnl_strdup(buf + eol + 1);
			break ;
		}
	}
	free(buf);
	if (!lst)
		return (NULL);
	line = join_list(lst);
	while (lst)
	{
		t_list *tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
	return (line);
}

