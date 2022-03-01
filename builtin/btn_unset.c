/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:32:28 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/09 16:32:41 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_env	*first(t_env *env)
{
	while (env->prev != NULL)
		env = env->prev;
	return (env);
}

void	remove_node(t_env **env)
{
	t_env	*tmp1;
	t_env	*tmp2;

	tmp1 = (*env)->prev;
	tmp2 = (*env)->next;
	if (tmp1 != NULL)
		tmp1->next = tmp2;
	if (tmp2 != NULL)
		tmp2->prev = tmp1;
	free((*env)->key);
	free((*env)->value);
	free(*env);
	if (tmp1 == NULL && tmp2 == NULL)
		*env = NULL;
	if (tmp1 != NULL)
		*env = first(tmp1);
	if (tmp2 != NULL)
		*env = first(tmp2);
}

int	btn_unset(char **keys, t_env **env)
{
	int		i;
	int		j;
	int		index;
	int		ext_code;

	j = 0;
	ext_code = 0;
	while (keys[j] != NULL)
	{
		index = get_env_index(keys[j], *env);
		if (index < 0 || *env == NULL)
			ext_code = -1;
		i = 0;
		while (i < index && *env != NULL)
		{
			*env = (*env)->next;
			i++;
		}
		if (*env == NULL)
			ext_code = -1;
		remove_node(env);
		*env = first(*env);
		j++;
	}
	return (ext_code);
}
