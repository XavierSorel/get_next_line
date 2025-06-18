
char 	*get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    *ft_strrchr(const char *str, int c);

typedef struct s_list
{
	char			content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;
