/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:49:28 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:46:57 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_PATH 1024
# define PIPE 1 
# define APPEND 2
# define REPLACE 3
# define INFILE 4
# define HEREDOC 5
# include <unistd.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
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
	char			*name;
	int				type;
	struct s_file	*next;
	struct s_file	*prev;
}				t_file;

typedef struct s_msh
{
	char			**cmd;
	int				rerror;
	int				input;
	int				output;
	int				pipein;
	int				pipeout;
	struct s_file	*infile;
	struct s_file	*outfile;
	pid_t			pid;
	pid_t			pid2;
	struct s_msh	*next;
	struct s_msh	*prev;
}			t_msh;

// MAIN
void		true_readline(t_env	**env);
// SIGNALS
void		sighandler(int mode);
// PARSING
t_msh		*parsing_exit(char **strtab);
int			var_error_check(char *line);
int			var_error(char *line);
t_msh		*parse_all(char *line, t_env **env);
	// PARSING ERROR
int			quotes_error(char **linetab);
int			endsep_error(char **linetab);
int			endpipecmd_error(char **linetab);
int			sep_error(char **linetab);
int			parsing_error(char **linetab);
	// PARSE ALL UTILS VAR
int			var_del(char c, char *line);
int			is_var(char *line);
int			var_cmp(char c, char *line);
	// VAR HEREDOC
char		*add_quotes(char *line);
char		*add_doc(char **linetab, int num, int len);
char		*var_heredoc(char *line);
	// SPLITLINE
int			is_sep(char c);
int			next_word(char *line);
int			check_quotes_utils(char *line);
int			check_quotes(char *line);
int			check_sep(char *line);
int			check_word(char *line);
int			get_word_len(char *line);
char		*word_cpy(char *line);
char		*word_cpy(char *line);
int			get_nbr_words(char *line);
void		fill_tab(char **linetab, char *line, int len);
char		**splitline(char *line);
	// HANDLE QUOTES
void		quotes_add(int *i, int *j);
void		noquotes_fill(char *tmp, char *line, int index, char c);
int			noquotes_size(char *line, int index, int c);
char		*remove_quote(char *line, int index);
void		handle_quotes(char **linetab);
		// HANDLE QUOTES UTILS NOSP
int			closed_quotes(char *line);
int			contain_no_quotes(char *line);
int			nosp_len(char *line);
void		nosp_fill(char *nosp, char *line);
char		*nosp(char *line);
	// VAR
char		*rep(char *line, t_env **env);
char		**var(char **linetab, t_env **env);
		// DELEMPTY
int			newtab_len(char **linetab);
void		fill_newtab(char **new, char **linetab);
void		free_chartwonull(char **linetab);
char		**delempty(char	**linetab, int null);
		// TMPVAR
int			novar_fill(char *line, char *tmp, int *sp);
int			check_var(char *line);
int			get_tmplen(char *line, t_env **env);
int			tmpadd(char *line, char *tmp, int sp, t_env **env);
void		fill_tmp(char *line, char *tmp, t_env **env);
			// TMPVAR UTILS
int			var_next(char *line, int *sp);
int			var_len(char *line, int sp, t_env **env);
			// GET VAR
char		*varname_exit(void);
char		*get_varname(char *line);
char		*get_var(char *line, int sp, t_env **env);
			// GET VAR QUOTES
int			contain_quote(char *line);
void		fill_quote_res(char *line, char *res, char c);
char		*quote_res(char *line);
		// VAR LOOP
void		check_loop_quotes(char c, int *tmp);
int			is_loop(char *key, char *value);
int			var_loop(char *line, t_env **env, int *tmp);
	// HANDLE MSH
void		last_rm(t_msh *msh);
int			init_files(t_msh *msh, char **linetab, int index);
void		init_msh(t_msh **msh, char **linetab);
t_msh		*handle_msh(char **linetab);
		// INIT MSH
void		add_cmd(t_msh **msh, t_msh *tmpmsh);
int			get_rerror(char **linetab);
void		fill_cmd(char **linetab, char **cmd);
int			get_argnb(char **linetab);
		// INIT FILES
int			is_file(char **linetab, int index);
void		set_pipe(t_msh *msh, char **linetab, int index);
void		add_file(t_file **files, int type, char *name);
void		af_msh(t_msh *msh, char **linetab);
void		bf_msh(t_msh *msh, char **linetab, int index);
// LIB
long long	ft_atoi(char *s);
void		*ft_calloc(size_t count, size_t size);
int			ft_charset(char *charset, char c);
char		**duptwotab(char **tab);
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
void		ft_putchar_fd(char c, int fd);
char		**ft_split(const char *str, char c);
void		ft_strcat(char *dst, char *src);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strjoins(char *str1, char *str2, char *str3);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strlen(char *str);
int			ft_count_occur(char *str, char c);
// BUILTIN
int			is_btn(char *arg);
int			is_dir(char *path);
int			btn_pwd(void);
int			btn_echo(t_msh *msh, int nl);
int			btn_env(t_env *env);
int			btn_unset(char **keys, t_env **env);
int			btn_cd(t_env **env, char *path);
int			btn_cd_old(t_env **env);
int			btn_cd_home(t_env **env);
int			btn_cd_dot(t_env **env);
int			btn_cd_back(t_env **env);
int			btn_exit(t_env *env, t_msh *msh);
int			is_too_big(char *cmd);
	// REDIR
int			btn_pwd_redir(t_msh *msh);
int			btn_echo_redir(t_msh *msh, int fd, int nl);
int			btn_env_redir(t_env *env, t_msh *msh);
int			btn_export_redir(t_msh *msh, t_env **env);
	// EXPORT
char		*strjoinenv(t_env *env);
void		fill_joinenv(char *joined, char *key, char *value);
void		error_export(char *arg, char *msg);
void		sort_env(char **strs);
void		btn_export_empty(t_env *env, int output);
int			btn_export(t_msh *msh, t_env **env);
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
void		free_exe(t_env *env, t_msh *msh);
void		free_all(t_env *env, t_msh *msh);
void		free_env(t_env *env);
void		free_lst(t_list *lst);
void		free_msh(t_msh *msh);
// EXE
	// EXE ALL
void		exit_status(int ext, int btn);
void		last_cmd(t_msh *msh, t_env **env);
void		handle_cmd(t_msh *msh, t_env **env, int *btn);
void		exe_all(t_env **env, t_msh *msh);
	// EXE BTN
int			check_nl_echo(char *string);
void		exe_btn_redir(t_env **env, t_msh *msh);
void		exe_btn(t_env **env, t_msh *msh);
	// EXE CMD
void		exe_cmd(t_msh *msh, t_env **env);
	// PATH UTILS
void		exit_path(t_msh *msh, t_env **env, int status);
int			is_path(t_msh *msh, t_env **env);
int			check_path(char *name, char *path, pid_t pid);
char		*get_path(t_msh *msh, char **path);
	// CLOSE
void		close_fd(t_msh *msh);
void		destroy_heredoc(t_msh *msh);
void		close_all_files(t_msh *msh);
void		close_all(t_msh *msh);
// HEREDOC
char		*read_heredoc(t_file *file);
void		write_heredoc(t_file *infile, int *fd);
void		create_heredoc(t_file *infile, int mode, int *ext);
void		init_all_heredoc(t_file *infile, int *ext);
int			init_heredoc(t_msh *msh, int *ext);
	// HEREDOC UTILS
char		*get_namedoc(void);
char		*dup_doc(char *s);
char		*join_doc(char *s1, char *s2);
void		send_heredoc(char *heredoc, t_file *infile);
char		*get_heredoc(int fd);
// PIPE
void		init_pipe(t_msh *msh);
// FILES
int			check_infile(t_file *infile, t_msh *msh);
int			check_outfile(t_file *outfile, t_msh *msh);
int			check_files(t_file *infile, t_file *outfile, t_msh *msh);
	// FILES UTILS
int			get_outfile_fd(char *name);
int			get_fd(t_msh *msh, char *name);
int			already_open_file(t_file *file, char *name);
int			already_open(t_msh *msh, char *name);
// REDIR
int			check_rerror(t_msh *msh);
void		close_fd_redir(t_msh *msh);
void		redirect_input(t_msh *msh);
void		redirect_output(t_msh *msh);
void		redir(t_msh *msh);

#endif