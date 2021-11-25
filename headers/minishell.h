/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:49:28 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/25 12:18:30 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_PATH 200
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

# define ECHO "echo"
# define CD "cd"
# define PWD "pwd"
# define EXPORT "export"
# define UNSET "unset"
# define ENV "env"
# define EXIT "exit"

typedef struct s_elem
{
	char			*word;
	struct s_elem	*next;
}				t_elem;

typedef struct s_start
{
	int		init;
	t_elem	*first;
}				t_start;

typedef struct s_msh
{
	int		in;
	int		out;
	int		exit;
	char	*line;
	t_start	*words;
}			t_msh;

// STATIC
t_msh	*st_mini(void);
t_start	*st_words(void);
// LIB
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	**ft_newarray(size_t w, size_t h, size_t size);
char	**ft_split(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_lst_split(const char *str, char c);
int		ft_strlen(char *str);
int		ft_charset(char *charset, char c);

// LINKED LISTS
int		ft_lstlen(t_start *start);
int		ft_lst_join(void);
int		ft_lst_count_occur(t_start *lst, char c);
int		ft_lst_new_elem(char *word, t_start *start);
void	ft_lst_add_top(t_elem *elem, t_start *start);
void	ft_lst_add_bot(t_elem *elem, t_start *start);
void	ft_lst_free(t_start *start);
void	ft_lst_show(t_start *stack);
t_elem	*ft_lst_before_last(t_start *start);
t_elem	*ft_lst_last_elem(t_start *start);

// PARSING
void	parsing_base(void);

#endif