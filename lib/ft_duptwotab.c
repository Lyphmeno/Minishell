/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duptwotab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 12:17:13 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:45:13 by hlevi            ###   ########.fr       */
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

char	**duptwotab(char **tab)
{
	int		i;
	int		size;
	char	**cpy;

	i = 0;
	size = get_size(tab);
	cpy = malloc(sizeof(char *) * (size + 1));
	if (cpy == NULL)
		return (NULL);
	while (tab[i] != NULL)
	{
		cpy[i] = ft_strdup(tab[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
