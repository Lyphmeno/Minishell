/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:26:20 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/09 16:27:12 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_path_cd(char *path)
{
	char	*sterror;

	if (access(path, F_OK) == -1)
	{
		sterror = ft_strjoins("minishell: cd: ", path,
				": No such file or directory");
		ft_putendl_fd(sterror, 2);
		free(sterror);
		return (-1);
	}
	if (is_dir(path) == 0)
	{
		sterror = ft_strjoins("minishell: cd: ", path, ": is not a directory");
		ft_putendl_fd(sterror, 2);
		free(sterror);
		return (-1);
	}
	if (access(path, X_OK) == -1)
	{
		sterror = ft_strjoins("minishell: cd: ", path, ": Permission denied");
		ft_putendl_fd(sterror, 2);
		free(sterror);
		return (-1);
	}
	return (0);
}

int	btn_cd_dot(t_env **env)
{
	char	path[MAX_PATH];

	getcwd(path, MAX_PATH);
	if (get_env_index("OLDPWD", *env) == -1)
		add_env("OLDPWD", path, env);
	else
		set_env("OLDPWD", path, *env);
	return (0);
}

int	btn_cd_home(t_env **env)
{
	int		ext_code;
	char	*path;

	path = get_env("HOME", *env);
	if (path == NULL)
	{
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (-1);
	}
	else
	{
		ext_code = btn_cd(env, path);
		return (0);
	}
	return (ext_code);
}

int	btn_cd_old(t_env **env)
{
	int		ext_code;
	char	*path;

	path = get_env("OLDPWD", *env);
	if (path == NULL)
	{
		ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
		return (-1);
	}
	ext_code = btn_cd(env, path);
	return (ext_code);
}

int	btn_cd(t_env **env, char *path)
{
	char	*old_path;
	char	new_path[MAX_PATH];

	if (check_path_cd(path) == -1)
		return (-1);
	old_path = ft_strdup(get_env("PWD", *env));
	if (chdir(path) == -1)
	{
		if (old_path != NULL)
			free(old_path);
		return (-1);
	}
	getcwd(new_path, MAX_PATH);
	if (get_env_index("PWD", *env) == -1)
		add_env("PWD", new_path, env);
	else
		set_env("PWD", new_path, *env);
	if (get_env_index("PWD", *env) == -1)
		add_env("OLDPWD", old_path, env);
	else
		set_env("OLDPWD", old_path, *env);
	if (old_path != NULL)
		free(old_path);
	return (0);
}
