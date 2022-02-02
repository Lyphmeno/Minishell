/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:01:07 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/26 16:57:39 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_path(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] == '\0')
	{
		if (cmd[i] == '/')
			return (1);
		i++;
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
			/*No such file or directory*/
		return (0);
	}
	if (access(path, X_OK) != 0)
	{
		if (name == NULL)
			/*No such file or directory*/
		else
			/*Permission denied*/
		return (-1);
	}
	return (1);
}

char	*get_path(t_env *env, char *cmd)
{
	int		i;
	char	*pathline;
	char	**pathtab;

	i = 0;
	pathtab = ft_split(get_env("PATH", env), ':');
	if (pathtab == NULL)
	{
		/*Envoyer un msg d'erreur PATH not set*/
		return (NULL);
	}
	while (pathtab[i] != NULL)
	{
		pathline = ft_strjoinmore(pathline[i++], "/", cmd);
		if (check_path(cmd, pathline) == -1)
		{
			free(pathline);
			return (NULL);
		}
		if (check_path(cmd, pathline) == 1)
			return (pathline);
		free(pathline);
	}
	/*Msg d'erreur Command not found*/
	return (NULL);
}

void	exe_cmd(t_env *env, char *cmd, char *arg, char *tmpath)
{
	char	**envtab;
	char	**argtab;

	envtab = ft_listotab(env);
	// argtab = ft_argtotab(arg);
	// FREE SHELL
	if (execve(tmpath, argtab, envtab) == -1)
	{
		free(tmpath);
		free(envtab);
		free(argtab);
		exit(1);
	}
}

void	exe_all(t_env *env, char *cmd, char *arg)
{
	char	*tmpath;

	tmpath = NULL;
	if (is_btn(cmd) == 1)
	{
		exe_btn_all(env, cmd, arg);
		// FREE SHELL;
		exit(0);
	}
	if (is_path(cmd) == 1)
	{
		if (check_path(NULL, cmd) == 1)
			tmpath = ft_strdup(cmd);
	}
	else
		tmpath = get_path(env, cmd);
	if (tmpath == NULL)
	{
		// FREE SHELL
		exit(1);
	}
	else
		exe_cmd(env, cmd, arg, tmpath);
}
