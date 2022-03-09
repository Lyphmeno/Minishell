/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_btn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:21:02 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/09 13:47:36 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_nl_echo(char *string)
{
	int	i;

	i = 1;
	if (string[0] && string[0] == '-')
	{
		while (string[i] != '\0')
		{
			if (string[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

static int	exe_cd(t_env **env, t_msh *msh)
{
	int	ext;

	if (msh->cmd[1] != NULL && msh->cmd[2] != NULL)
	{
		ft_putendl_fd("minishell: cd: too many arguments", 2);
		ext = 1;
	}
	else if (ft_strcmp(msh->cmd[1], "-") == 0)
		ext = btn_cd_old(env);
	else if (ft_strcmp(msh->cmd[1], "..") == 0)
		ext = btn_cd_back(env);
	else if (ft_strcmp(msh->cmd[1], ".") == 0)
		ext = btn_cd_dot(env);
	else if (msh->cmd[1] == NULL)
		ext = btn_cd_home(env);
	else
		ext = btn_cd(env, msh->cmd[1]);
	return (ext);
}

int	exe_echo(t_msh *msh)
{
	int	ext;

	if (!msh->cmd[1])
	{
		write(1, "\n", 1);
		return (0);
	}
	if (check_nl_echo(msh->cmd[1]) == 0)
		ext = btn_echo(msh, 0);
	else
		ext = btn_echo(msh, 1);
	return (ext);
}

void	exe_btn(t_env **env, t_msh *msh)
{
	int	ext;

	ext = 0;
	if (ft_strcmp(msh->cmd[0], "cd") == 0)
		ext = exe_cd(env, msh);
	if (ft_strcmp(msh->cmd[0], "echo") == 0)
		ext = exe_echo(msh);
	if (ft_strcmp(msh->cmd[0], "env") == 0)
		ext = btn_env(*env);
	if (ft_strcmp(msh->cmd[0], "exit") == 0)
		ext = btn_exit(*env, msh);
	if (ft_strcmp(msh->cmd[0], "export") == 0)
		ext = btn_export(msh, env);
	if (ft_strcmp(msh->cmd[0], "pwd") == 0)
		ext = btn_pwd();
	if (ft_strcmp(msh->cmd[0], "unset") == 0)
		ext = btn_unset(msh->cmd, env);
	if (msh->next != NULL || msh->prev != NULL)
	{
		close(5);
		free_all(*env, msh);
		exit(ext);
	}
	g_exit = ext;
}
