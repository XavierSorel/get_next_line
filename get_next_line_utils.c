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

size_t	gnl_strlen(const char *s)
{
	size_t	len = 0;
	while (s && s[len])
		len++;
	return (len);
}

char	*gnl_strdup(const char *s)
{
	size_t	len = gnl_strlen(s);
	char	*dup = malloc(len + 1);
	size_t	i = 0;

	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	gnl_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d = gnl_strlen(dst);
	size_t	s = 0;

	if (size <= d)
		return (size + gnl_strlen(src));
	while (src[s] && d + s + 1 < size)
	{
		dst[d + s] = src[s];
		s++;
	}
	dst[d + s] = '\0';
	return (d + gnl_strlen(src));
}

int	find_eol(const char *s)
{
	int	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*join_list(t_list *lst)
{
	size_t	total = 0;
	char	*joined;
	t_list	*cur = lst;

	while (cur)
	{
		total += gnl_strlen(cur->content);
		cur = cur->next;
	}
	joined = malloc(total + 1);
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	cur = lst;
	while (cur)
	{
		gnl_strlcat(joined, cur->content, total + 1);
		cur = cur->next;
	}
	return (joined);
}

