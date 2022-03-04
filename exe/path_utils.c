/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:02:00 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:47:39 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*send_err_msg(char *name, char mode, pid_t pid)
{
	char	*err_msg;

	if (pid != 0)
		return (NULL);
	if (mode == 'C')
		err_msg = ft_strjoins("minishell: ", name, ": command not found");
	if (mode == 'F')
		err_msg = ft_strjoins("minishell: ", name,
				": No such file or directory");
	if (mode == 'X')
		err_msg = ft_strjoins("minishell: ", name, ": permission denied");
	if (mode == 'P')
		err_msg = ft_strjoins("minishell: ", name, ": PATH not set");
	if (mode == 'D')
		err_msg = ft_strjoins("minishell: ", name, ": is a directory");
	if (err_msg != NULL)
	{
		ft_putendl_fd(err_msg, 2);
		free(err_msg);
	}
	return (NULL);
}

int	is_path(t_msh *msh, t_env **env)
{
	int	i;
	int	c;

	if (!msh->cmd[0])
		return (0);
	i = 0;
	c = 0;
	if (ft_strcmp(msh->cmd[0], ".") == 0)
	{
		ft_putendl_fd("minishell: syntax error", 2);
		exit_path(msh, env, 2);
	}
	while (msh->cmd[0][i] != '\0')
	{
		if (msh->cmd[0][i] == '/')
			return (1);
		if (msh->cmd[0][i++] == '.')
			c++;
	}
	if (ft_strlen(msh->cmd[0]) == c)
	{
		send_err_msg(msh->cmd[0], 'C', msh->pid);
		exit_path(msh, env, 127);
	}
	return (0);
}

int	check_path(char *name, char *path, pid_t pid)
{
	if (path == NULL)
		return (0);
	if (access(path, F_OK) != 0)
	{
		if (name == NULL)
			send_err_msg(path, 'F', pid);
		return (0);
	}
	if (access(path, X_OK) != 0)
	{
		if (name == NULL)
			send_err_msg(path, 'X', pid);
		else
			send_err_msg(name, 'X', pid);
		return (-1);
	}
	if (is_dir(path) == 1)
	{
		if (name == NULL)
			send_err_msg(path, 'D', pid);
		else
			send_err_msg(name, 'D', pid);
		return (-1);
	}
	return (1);
}

char	*get_path(t_msh *msh, char **path)
{
	int		i;
	char	*full_path;

	i = 0;
	if (path == NULL)
		return (send_err_msg(msh->cmd[0], 'P', msh->pid));
	if (ft_strcmp(msh->cmd[0], "\0") == 0)
		return (send_err_msg(NULL, 'C', msh->pid));
	while (path[i] != NULL)
	{
		full_path = ft_strjoins(path[i++], "/", msh->cmd[0]);
		if (check_path(msh->cmd[0], full_path, msh->pid) == -1)
		{
			free(full_path);
			return (NULL);
		}
		if (check_path(msh->cmd[0], full_path, msh->pid) == 1)
			return (full_path);
		free(full_path);
	}
	return (send_err_msg(msh->cmd[0], 'C', msh->pid));
}
