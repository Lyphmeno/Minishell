/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:18:40 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/26 16:48:18 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_size(t_env *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**ft_listotab(t_env *env)
{
	int		i;
	char	**tab;

	i = 0;
	if (env == NULL)
		return (NULL);
	tab = (char **)ft_newarray(sizeof(char *),
			get_size(env) + 1, sizeof(char*));
	while (env)
	{
		tab[i] = ft_strjoinmore(env->key, "=", env->value);
		env = env->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
