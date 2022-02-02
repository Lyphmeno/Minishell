/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_btn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:21:02 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/26 13:58:05 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_nl_echo(char *arg)
{
	int	i;

	i = 2;
	if (arg[0] == '-' && arg[1] == 'n')
	{
		while (arg[i] != " " && arg[i])
		{
			if (arg[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	exe_cd(t_env *env, char *arg)
{
	int	exit_code;

	if (ft_strcmp(arg, "-") == 0)
		exit_code = btn_cd_old(env);
	else if (ft_strcmp(arg, "..") == 0)
		exit_code = btn_cd_back(env);
	else if (ft_strcmp(arg, ".") == 0)
		exit_code = btn_cd_dot(env);
	else if (arg == NULL)
		exit_code = btn_cd_home(env);
	else
		exit_code = btn_cd(&env, arg);
	return (exit_code);
}

void	exe_echo(char *arg)
{
	if (check_nl_echo(arg) == 1)
		btn_echo(arg, 1);
	else
		btn_echo(arg, 0);
}

void	exe_btn_all(t_env *env, char *cmd, char *arg)
{
	int	exit_code;

	exit_code = 0;
	if (ft_strcmp(cmd, "cd") == 0)
		exit_code = exe_cd(env, arg);
	if (ft_strcmp(cmd, "echo") == 0)
		exe_echo(arg);
	if (ft_strcmp(cmd, "env") == 0)
		btn_env(env);
	if (ft_strcmp(cmd, "exit") == 0)
		exit_code = btn_exit(env, arg);
	if (ft_strcmp(cmd, "export") == 0)
		exit_code = btn_export(&env, arg);
	if (ft_strcmp(cmd, "pwd") == 0)
		exit_code = btn_pwd();
	if (ft_strcmp(cmd, "unset") == 0)
		exit_code = btn_unset(arg, &env);
}
