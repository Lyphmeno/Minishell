/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_btn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:21:02 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/20 15:51:57 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

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

int	exe_echo(char *arg)
{
	int	exit_code;

	if (arg[0] == '-' && arg[1] == 'n')
		exit_code = btn_echo(arg, 1);
	else
		exit_code = btn_echo(arg, 0);
}

void	exe_btn_all(t_env *env, /*list, int cmd*/)
{
	int	exit_code;

	if (ft_strcmp(get_cmd(cmd, list), "cd") == 0)
		exit_code = exe_cd(env, get_args(cmd, list));
	if (ft_strcmp(get_cmd(cmd, list), "echo") == 0)
		exit_code = exe_echo(get_args(cmd, list));
	if (ft_strcmp(get_cmd(cmd, list), "env") == 0)
		exit_code = btn_env(env);
	if (ft_strcmp(get_cmd(cmd, list), "exit") == 0)
		exit_code = btn_exit(env, get_args(cmd, list));
	if (ft_strcmp(get_cmd(cmd, list), "export") == 0)
		exit_code = btn_export(&env, get_args(cmd, list));
	if (ft_strcmp(get_cmd(cmd, list), "pwd") == 0)
		exit_code = btn_pwd();
	if (ft_strcmp(get_cmd(cmd, list), "unset") == 0)
		exit_code = btn_unset(get_args(cmd, list), &env);
}
