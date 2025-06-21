#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct t_list
{
        char                    content[10];
        struct t_list   *next;
}       t_list;


t_list  *ft_lstnew(char *content)
{
        printf("im in ft_lstnew\n");
        t_list  *new_node;
        int     i;

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
        printf("im in lstadd_back Start\n");
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
        printf("im in lstadd_back End\n");
}

int	 main()
{
	t_list	*node;
	t_list 	*list;

	list = NULL;
	node = ft_lstnew("hola");
	ft_lstadd_back(&list, node);
	printf("%s\n", node->content);
	return (0);
}
