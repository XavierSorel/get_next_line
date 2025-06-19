#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>


typedef struct t_list
{
        char                    content[BUFFER_SIZE + 1];
        struct t_list   *next;
}       t_list;

char 	*get_next_line(int fd);
char    *ft_merge_lst_return(t_list **lst, size_t len, char *full_line);
void    ft_lstadd_back(t_list **lst, t_list *new);
//size_t  ft_strlen(const char *str);
int	ft_strrchr(const char *str);
t_list  *ft_lstnew(char *content);
void    free_all(t_list **lst);
