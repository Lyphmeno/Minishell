/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:01:07 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:27:12 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	exit_status(int ext, int btn)
{
	if (ext == 2)
		g_exit = 130;
	else if (ext == 131)
		g_exit = 131;
	else if (btn == 0)
		g_exit = ext >> 8;
}

void	last_cmd(t_msh *msh, t_env **env)
{
	char	**path;
	char	*full_path;

	path = ft_split(get_env("PATH", *env), ':');
	full_path = get_path(msh, path);
	free_twochar(path);
	if (full_path)
	{
		if (get_env_index("_", *env) == -1)
			add_env("_", full_path, env);
		else
			set_env("_", full_path, *env);
		free(full_path);
	}
	else
	{
		if (get_env_index("_", *env) == -1)
			add_env("_", msh->cmd[0], env);
		else
			set_env("_", msh->cmd[0], *env);
	}
}

void	handle_cmd(t_msh *msh, t_env **env, int *btn)
{
	msh->pid = 1;
	if (is_btn(msh->cmd[0]) == 1 && msh->next == NULL && msh->prev == NULL)
	{
		*btn = 1;
		if (check_rerror(msh))
			return ;
		last_cmd(msh, env);
		if (msh->outfile != NULL)
			exe_btn_redir(env, msh);
		else
			exe_btn(env, msh);
	}
	else if (msh->cmd[0] != NULL)
	{
		last_cmd(msh, env);
		msh->pid = fork();
		if (msh->pid == 0)
		{
			sighandler(3);
			exe_cmd(msh, env);
		}
	}
}

void	exe_all(t_env **env, t_msh *msh)
{
	int		ext;
	int		btn;
	t_msh	*tmpmsh;

	ext = 0;
	btn = 0;
	tmpmsh = msh;
	if (init_heredoc(msh, &ext) == 0)
		return ;
	while (msh != NULL)
	{
		init_pipe(msh);
		if (check_files(msh->infile, msh->outfile, msh) == 1)
		{
			g_exit = -1;
			handle_cmd(msh, env, &btn);
			close_fd(msh);
			waitpid(msh->pid, &ext, 0);
			exit_status(ext, btn);
		}
		close_fd(msh);
		msh = msh->next;
	}
	close_all(tmpmsh);
}
