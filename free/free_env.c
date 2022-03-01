/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:40:57 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/17 15:34:40 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_env(t_env *env)
{
	t_env	*tmp;

	if (env == NULL)
		return ;
	while (env->prev != NULL)
		env = env->prev;
	while (env != NULL)
	{
		tmp = env->next;
		if (env->key != NULL)
			free(env->key);
		if (env->value != NULL)
			free(env->value);
		free(env);
		env = tmp;
	}
}
