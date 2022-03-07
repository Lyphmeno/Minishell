/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:39:06 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:47:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	close_fd_exe(void)
{
	close(0);
	close(1);
	close(2);
}

void	exit_path(t_msh *msh, t_env **env, int status)
{
	int	exit_status;

	exit_status = 1;
	if (status == 127 || access(msh->cmd[0], F_OK) != 0)
		exit_status = 127;
	else if (status == 2)
		exit_status = 2;
	else if (is_dir(msh->cmd[0]) == 1
		|| (access(msh->cmd[0], F_OK) == 0
			&& access(msh->cmd[0], X_OK) != 0))
		exit_status = 126;
	free_all(*env, msh);
	exit(exit_status);
}

void	exit_rerror(t_msh *msh, t_env **env)
{
	ft_putendl_fd("minishell: ambiguous redirect", 2);
	free_all(*env, msh);
	exit (1);
}

void	exe_path(char *tmp, t_msh *msh, t_env *env)
{
	char	**cmdtab;
	char	**envtab;

	if (tmp == NULL)
	{
		free_all(env, msh);
		exit(127);
	}
	else
	{
		envtab = ft_envtotab(env);
		cmdtab = duptwotab(msh->cmd);
		free_exe(env, msh);
		if (execve(tmp, cmdtab, envtab) == -1)
		{
			free(tmp);
			free_twochar(cmdtab);
			free_twochar(envtab);
			close_fd_exe();
			exit(1);
		}
	}
}

void	exe_cmd(t_msh *msh, t_env **env)
{
	char	*tmp;
	char	**path;

	if (msh->rerror == 1)
		exit_rerror(msh, env);
	path = ft_split(get_env("PATH", *env), ':');
	tmp = NULL;
	sighandler(2);
	redir(msh);
	if (is_btn(msh->cmd[0]) == 1)
	{
		//free_twochar(path);
		exe_btn(env, msh);
	}
	else if (is_path(msh, env) == 1)
	{
		if (check_path(NULL, msh->cmd[0], msh->pid) == 1)
			tmp = ft_strdup(msh->cmd[0]);
		else
			exit_path(msh, env, 0);
	}
	else
		tmp = get_path(msh, path);
	free_twochar(path);
	exe_path(tmp, msh, *env);
}
