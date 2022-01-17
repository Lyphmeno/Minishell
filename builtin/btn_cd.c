/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:26:20 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/15 16:28:59 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_path(char *path)
{
	char	*sterror;

	if (access(path, F_OK) == -1)
	{
		sterror = ft_strjoin("minishell: cd: ", path);
		sterror = ft_strjoin(sterror, "No such file or directory");
		ft_putstr_fd(sterror, 2);
		free(sterror);
		return (-1);
	}
	else if (access(path, X_OK) == -1)
	{
		sterror = ft_strjoin("minishell: cd: ", path);
		sterror = ft_strjoin(sterror, "Permission denied");
		ft_putstr_fd(sterror, 2);
		free(sterror);
		return (-1);
	}
	return (0);
}

int	btn_cd_dot(t_env *env)
{
	char	path[MAX_PATH];

	getcwd(path, MAX_PATH);
	btn_unset("OLDPWD", &env);
	add_env("OLDPWD", path, &env);
	return (0); 
}

int	btn_cd_home(t_env *env)
{
	int		ext_code;
	char	*path;

	path = get_env("HOME", env);
	if (path == NULL)
	{
		ft_putstr_fd("minishell: cd: HOME not set", 2);
		return (-1);
	}
	ext_code = btn_cd(&env, path);
	return (ext_code);
}

int	btn_cd_old(t_env *env)
{
	int		ext_code;
	char	*path;

	path = get_env("OLDPWD", env);
	if (path == NULL)
	{
		ft_putstr_fd("minishell: cd: OLDPWD not set", 2);
		return (-1);
	}
	ext_code = btn_cd(&env, path);
	return (ext_code);
}

int	btn_cd(t_env **env, char *path)
{
	char	old_path[MAX_PATH];
	char	new_path[MAX_PATH];

	if (check_path(path) == -1)
		return (-1);
	getcwd(old_path, MAX_PATH);
	if (chdir(path) == -1)
		return (-1);
	getcwd(new_path, MAX_PATH);
	btn_unset("PWD", env);
	add_env("PWD", new_path, env);
	btn_unset("OLDPWD", env);
	add_env("OLDPWD", old_path, env);
	return (0);
}
