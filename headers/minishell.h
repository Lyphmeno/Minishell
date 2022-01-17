/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:49:28 by hlevi             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/29 16:31:57 by jchene           ###   ########.fr       */
=======
/*   Updated: 2022/01/17 12:43:26 by hlevi            ###   ########.fr       */
>>>>>>> hugo
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_PATH 1024
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_elem
{
	char			*word;
	struct s_elem	*prev;
	struct s_elem	*next;
}				t_elem;

typedef struct s_start
{
	int		init;
	t_elem	*first;
}				t_start;

typedef struct s_msh
{
	char	*line;
	t_start	*words;
}			t_msh;

// STATIC
t_msh	*st_mini(void);
t_start	*st_words(void);
// LIB
void	*ft_calloc(size_t count, size_t size);
int		ft_is_digit(int c);
void	*ft_memset(void *b, int c, size_t len);
void	**ft_newarray(size_t w, size_t h, size_t size);
char	**ft_split(const char *str, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_lst_split(const char *str, char c);
int		ft_strlen(char *str);
int		ft_charset(char *charset, char c);
int		ft_count_occur(char *str, char c);
char	*ft_strdup(char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strcat(char *dst, char *src);
// LINKED LISTS
int		ft_lstlen(t_start *start);
int		ft_lst_count_occur(t_start *lst, char c);
int		ft_lst_join(void);
int		ft_lst_join_size(t_elem *start, t_elem *stop);
int		ft_lst_elem_join(t_start *lst, t_elem *start, t_elem *stop);
void	ft_lst_add_top(t_elem *elem, t_start *start);
void	ft_lst_add_bot(t_elem *elem, t_start *start);
void	ft_lst_free_elem(t_elem *elem, t_start *lst);
void	ft_lst_free(t_start *start);
void	ft_lst_show(t_start *stack);
t_elem	*ft_lst_new_elem(char *word);
t_elem	*ft_lst_before_last(t_start *start);
t_elem	*ft_lst_last_elem(t_start *start);
t_elem	*ft_lst_next_occur(t_elem *elem, char c);
// PARSING
void	parsing_base(void);
// BUILTIN
int		bin_pwd(void);
void	bin_echo(char *text, int nl);
void	btn_env(t_env *env);
void	btn_unset(char *key, t_env **env);
void	btn_export(char *src, t_env **env);
int		btn_cd(t_env **env, char *path);
int		btn_cd_old(t_env *env);
int		btn_cd_home(t_env *env);
int		btn_cd_dot(t_env *env);
int		btn_cd_back(t_env *env);
// ENV
t_env	*parse_env(char **envp);
void	add_env(char *name, char *value, t_env **env);
char	*get_env(char *name, t_env *env);
char	*get_key(char *envp);
char	*get_value(char *envp);
int		get_env_index(char *name, t_env *env);

#endif