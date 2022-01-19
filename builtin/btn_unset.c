/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:32:28 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/19 13:44:03 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	remove_node(t_env **env, t_env *toDel)
{
	if (*env == NULL && toDel == NULL)
		return ;
	if (*env == toDel)
		*env = toDel->next;
	if (toDel->next != NULL)
		toDel->next->prev = toDel->prev;
	if (toDel->prev != NULL)
		toDel->prev->next = toDel->next;
	free(toDel->key);
	free(toDel->value);
	free(toDel);
}

void	btn_unset(char *key, t_env **env)
{
	int		i;
	int		index;
	t_env	*current;

	index = get_env_index(key, *env);
	if (index < 0 || env == NULL)
		return ;
	current = *env;
	i = 1;
	while (i < index && current != NULL)
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return ;
	remove_node(env, current);
}
