/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:49:28 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 19:31:21 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_PATH 1024
# define CMD 0
# define ARG 1
# define PIPE 2
# define REDIR 3
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

int	g_exit;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct s_list
{
	char			*word;
	int				flag;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

typedef struct s_file
{
	char			*value;
	int				type;
	struct s_file	*next;
	struct s_file	*prev;
}				t_file;

typedef struct s_msh
{
	char			*cmd;
	char			**arg;
	int				argnb;
	int				input;
	int				output;
	int				pipein;
	int				pipeout;
	struct s_file	infile;
	struct s_file	outfile;
	pid_t			pid;
	struct s_msh	*next;
	struct s_msh	*prev;
}			t_msh;

// MAIN
void		true_readline(t_env	**env);

// PARSING
t_msh		*parse_all(char *line, t_env **env);
// VAR
int			is_var(char *line);
int			var_cmp(char c, char *line);
// VAR HEREDOC
char		*add_quotes(char *line);
char		*add_doc(char **linetab, int num, int len);
char		*var_heredoc(char *line);


// LIB
long long	ft_atoi(char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_charset(char *charset, char c);
char		**duptwotab(char *tmp, char **tab);
void		free_twochar(char **tab);
int			ft_is_digit(int c);
char		*ft_itoa(int n);
char		**ft_envtotab(t_env *env);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		**ft_newarray(size_t w, size_t h, size_t size);
void		ft_printarray(char **array);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *str, int fd);
char		**ft_split(const char *str, char c);
void		ft_strcat(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoins(char *str1, char *str2, char *str3);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strlen(char *str);
void		ft_cmdtotab(t_msh *msh, t_list *list);
int			ft_count_occur(char *str, char c);
// LINKED LISTS
int			ft_lst_split(t_list **list, char *str, char c);
void		ft_lst_add_bot(t_list **list, char *word);
void		ft_lst_add_top(t_list **list, t_list *new);
t_list		*ft_lst_new_elem(char *word);
int			ft_lstlen(t_list *list);
// PARSING J
int			parsing_base(char *line, t_list **list);
// BUILTIN
int			is_btn(char *arg);
int			btn_pwd(void);
void		btn_echo(t_msh *msh, int nl);
void		btn_env(t_env *env);
int			btn_unset(char **keys, t_env **env);
int			btn_export(t_msh *msh, t_env **env);
int			btn_cd(t_env **env, char *path);
int			btn_cd_old(t_env **env);
int			btn_cd_home(t_env **env);
int			btn_cd_dot(t_env **env);
int			btn_cd_back(t_env **env);
int			btn_exit(t_env *env, t_msh *msh);
// ENV
t_env		*parse_env(char **envp);
void		add_env(char *envkey, char *envalue, t_env **env);
char		*get_env(char *name, t_env *env);
char		*get_key(char *envp);
char		*get_value(char *envp);
int			get_env_index(char *name, t_env *env);
void		set_env(char *name, char *content, t_env *env);
void		env_export(t_env *env);
// FREE
void		free_all(t_env *env, t_msh *msh);
void		free_env(t_env *env);
void		free_exe(t_env *env, t_msh *msh);
void		free_lst(t_list *lst);
void		free_msh(t_msh *msh);
// EXE
void		exe_cmd(t_env **env, t_msh *msh);
void		exe_all(t_env **env, t_msh *msh);
void		exe_btn_all(t_env **env, t_msh *msh);
int			is_path(t_msh *msh, t_env **env);
int			is_dir(char *path);
void		error_msg(char *arg, char *msg);
int			check_path(char *cmd, char *path);
void		wrong_path(t_msh *msh, t_env **env, int status);
char		*get_path(t_msh *msh, char **path);
void		exe_path(char *tmp, t_msh *msh, t_env *env);

#endif