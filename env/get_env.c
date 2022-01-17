/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:44:40 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/12 16:17:13 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*get_env(char *name, t_env *env)
{
	while (env != NULL)
	{
		if (ft_strcmp(name, env->key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

int	get_env_index(char *name, t_env *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		if (ft_strcmp(name, env->key) == 0)
			return (i);
		env = env->next;
		i++;
	}
	return (-1);
}
