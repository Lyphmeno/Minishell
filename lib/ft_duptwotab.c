/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duptwotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:17:13 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 17:58:21 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	get_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**duptwotab(char *tmp, char **tab)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = ft_calloc(sizeof(char *), (get_size((tab) + 2)));
	cpy[0] = ft_strdup(tmp);
	while (tab[i] != NULL)
	{
		cpy[i + 1] = ft_strdup(tab[i]);
		i++;
	}
	cpy[i + 1] = NULL;
	return (cpy);
}
