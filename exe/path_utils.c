/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:02:00 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 15:14:52 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	wrong_path(t_msh *msh, t_env **env, int status)
{
	int	exit_status;

	exit_status = 1;
	if (status == 127 || access(msh->cmd, F_OK) != 0)
		exit_status = 127;
	else if (status == 2)
		exit_status = 2;
	else if (is_dir(msh->cmd) == 1
		|| (access(msh->cmd, F_OK) == 0
			&& access(msh->cmd, X_OK) != 0))
		exit_status = 126;
	free_all(*env, msh);
	exit(exit_status);
}

int	is_path(t_msh *msh, t_env **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!msh->cmd)
		return (0);
	if (ft_strcmp(msh->cmd, ".") == 0)
	{
		ft_putendl_fd("minishell: syntax error", 2);
		wrong_path(msh, env, 2);
	}
	while (msh->cmd[i] != '\0')
	{
		if (msh->cmd[i] == '/')
			return (i);
		if (msh->cmd[i++] == '.')
			j++;
	}
	if (ft_strlen(msh->cmd) == j)
	{
		error_msg(msh->cmd, ": command not found");
		wrong_path(msh, env, 127);
	}
	return (0);
}

int	check_path(char *cmd, char *path)
{
	if (path == NULL)
		return (0);
	if (access(path, F_OK) != 0)
	{
		if (cmd == NULL)
			error_msg(cmd, ": No such file or directory");
		return (0);
	}
	if (access(path, X_OK) != 0)
	{
		if (cmd == NULL)
			error_msg(cmd, ": No such file or directory");
		else
			error_msg(cmd, ": Permission denied");
		return (-1);
	}
	if (is_dir(path) == 1)
	{
		if (cmd == NULL)
			error_msg(cmd, ": is a directory");
		else
			error_msg(path, ": is a directory");
		return (-1);
	}
	return (1);
}

char	*get_path(t_msh *msh, char **path)
{
	int		i;
	char	*pathline;

	i = 0;
	if (path == NULL)
	{
		error_msg(msh->cmd, ": Path not set");
		return (NULL);
	}
	while (path[i])
	{
		pathline = ft_strjoins(path[i++], "/", msh->cmd);
		if (check_path(msh->cmd, pathline) == -1)
		{
			free(pathline);
			return (NULL);
		}
		if (check_path(msh->cmd, pathline) == 1)
			return (pathline);
		free(pathline);
	}
	error_msg(msh->cmd, ": command not found");
	return (NULL);
}
