/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_btn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:21:02 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/23 17:12:48 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_nl_echo(t_msh *msh)
{
	int	i;

	if (msh->arg[0] == NULL)
		return (-1);
	if (msh->arg[0][0] == '-' && msh->arg[0][1] == 'n')
	{
		i = 2;
		while (msh->arg[0][i] != ' ' && msh->arg[0][i])
		{
			if (msh->arg[0][i] != 'n')
				return (0);
			i++;
		}
		return (i);
	}
	return (0);
}

int	exe_cd(t_env **env, t_msh *msh)
{
	int	exit_code;

	if (ft_strcmp(msh->arg[1], "-") == 0)
		exit_code = btn_cd_old(env);
	else if (ft_strcmp(msh->arg[1], "..") == 0)
		exit_code = btn_cd_back(env);
	else if (ft_strcmp(msh->arg[1], ".") == 0)
		exit_code = btn_cd_dot(env);
	else if (msh->arg[1] == NULL)
		exit_code = btn_cd_home(env);
	else
		exit_code = btn_cd(env, msh->arg[1]);
	return (exit_code);
}

void	exe_echo(t_msh *msh)
{
	int	i;

	i = check_nl_echo(msh);
	btn_echo(msh, i);
}

void	exe_btn_all(t_env **env, t_msh *msh)
{
	int	exit_code;

	exit_code = 0;
	if (ft_strcmp(msh->cmd, "cd") == 0)
		exit_code = exe_cd(env, msh);
	if (ft_strcmp(msh->cmd, "echo") == 0)
		exe_echo(msh);
	if (ft_strcmp(msh->cmd, "env") == 0)
		btn_env(*env);
	if (ft_strcmp(msh->cmd, "exit") == 0)
		exit_code = btn_exit(*env, msh);
	if (ft_strcmp(msh->cmd, "export") == 0)
		exit_code = btn_export(msh, env);
	if (ft_strcmp(msh->cmd, "pwd") == 0)
		exit_code = btn_pwd();
	if (ft_strcmp(msh->cmd, "unset") == 0)
		exit_code = btn_unset(msh->arg, env);
	if (msh->cmd == NULL)
	{
		free_all(*env, msh);
		exit(exit_code);
	}
	g_exit = exit_code;
}
