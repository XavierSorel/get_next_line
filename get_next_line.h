#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


typedef struct t_list
{
        char                    *content;
        struct t_list   *next;
}       t_list;

char 	*get_next_line(int fd);
void    add_leftover_newline(t_list **new_line, char *leftover);
void	ft_merge_lst_return(t_list **lst, char **full_line);
void    ft_lstadd_back(t_list **lst, t_list *new);
size_t  ft_strlen(const char *str);
int	ft_strchr(const char *str);
t_list  *ft_lstnew(char *content);
int	size_return_str(t_list *lst);
void    free_all(t_list **lst);
