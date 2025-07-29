#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
} t_list;

char	*get_next_line(int fd);
char	*gnl_strdup(const char *s);
size_t	gnl_strlen(const char *s);
size_t	gnl_strlcat(char *dst, const char *src, size_t size);
int	find_eol(const char *s);
char	*join_list(t_list *lst);

#endif
