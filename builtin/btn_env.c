/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:54:24 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/12 14:44:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	btn_env(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			printf("%s=%s\n", tmp->key, tmp->value);
			tmp = tmp->next;
			i++;
		}
		printf("%s=%s\n", tmp->key, tmp->value);
		printf("\n========================================\n");
	}
}
