/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:01:07 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 18:04:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	exe_path(char *tmp, t_msh *msh, t_env *env)
{
	char	**envtab;
	char	**argtab;

	if (tmp == NULL)
	{
		free_all(env, msh);
		exit(127);
	}
	else
	{
		envtab = ft_envtotab(env);
		argtab = duptwotab(tmp, msh->arg);
		free_exe(env, msh);
		if (execve(tmp, argtab, envtab) == -1)
		{
			free(tmp);
			free_twochar(envtab);
			free_twochar(argtab);
			exit(1);
		}
	}
}

void	exe_cmd(t_env **env, t_msh *msh)
{
	char	*tmp;
	char	**path;

	path = ft_split(get_env("PATH", *env), ':');
	tmp = NULL;
	if (is_path(msh, env) == 1)
	{
		if (check_path(NULL, msh->cmd) == 1)
			tmp = ft_strdup(msh->cmd);
		else
			wrong_path(msh, env, 0);
	}
	else
		tmp = get_path(msh, path);
	free(path);
	exe_path(tmp, msh, *env);
}

void	exe_all(t_env **env, t_msh *msh)
{
	if (is_btn(msh->cmd) == 1)
	{
		exe_btn_all(env, msh);
	}
	else if (msh->cmd)
	{
		exe_cmd(env, msh);
	}
}
