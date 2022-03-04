/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:54:24 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 22:45:10 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	btn_env_redir(t_env *env, t_msh *msh)
{
	while (env != NULL)
	{
		if (ft_strcmp(env->key, "?") != 0)
		{
			ft_putstr_fd(env->key, msh->output);
			ft_putstr_fd("=", msh->output);
			if (env->value != NULL)
				ft_putendl_fd(env->value, msh->output);
			else
				ft_putstr_fd("\n", msh->output);
		}
		env = env->next;
	}
	return (0);
}

int	btn_env(t_env *env)
{
	while (env != NULL)
	{
		if (ft_strcmp(env->key, "?") != 0)
		{
			ft_putstr_fd(env->key, 1);
			ft_putstr_fd("=", 1);
			if (env->value != NULL)
				ft_putendl_fd(env->value, 1);
			else
				ft_putstr_fd("\n", 1);
		}
		env = env->next;
	}
	return (0);
}
