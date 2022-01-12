/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:32:28 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/12 17:01:21 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	btn_unset(char *key, t_env **env)
{
	int		index;
	// t_env	*tmp;
	// t_env	*prev;

	index = get_env_index(key, *env);
	if (index < 0)
		return ;
	// tmp = *env;
	// prev = NULL;
	// if (env != NULL)
	// {
	// 	while (tmp != NULL && index > 1)
	// 	{
	// 		prev = tmp;
	// 		tmp = tmp->next;
	// 		index--;
	// 	}
	// 	prev->next = tmp->next;
	// }
	// free(tmp);
}
