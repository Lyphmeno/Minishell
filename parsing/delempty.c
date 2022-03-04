/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delempty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:39:50 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 19:42:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	newtab_len(char **linetab)
{
	int	i;

	i = 0;
	while (linetab[i])
		i++;
	i++;
	while (linetab[i])
		i++;
	return (i);
}

void	fill_newtab(char **new, char **linetab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (linetab[i])
	{
		new[j] = ft_strdup(linetab[i]);
		i++;
		j++;
	}
	i++;
	while (linetab[i])
	{
		new[j] = ft_strdup(linetab[i]);
		i++;
		j++;
	}
	new[j] = NULL;
}

void	free_chartwonull(char **linetab)
{
	int	i;

	i = 0;
	while (linetab[i])
	{
		free(linetab[i]);
		i++;
	}
	i++;
	while (linetab[i])
	{
		free(linetab[i]);
		i++;
	}
	free(linetab);
}

char	**delempty(char	**linetab, int null)
{
	char	**new;
	int		len;

	if (null == 0)
		return (linetab);
	g_exit = 0;
	len = newtab_len(linetab);
	new = ft_calloc(sizeof(char *), len);
	if (!new)
	{
		free_chartwonull(linetab);
		return (NULL);
	}
	fill_newtab(new, linetab);
	free_chartwonull(linetab);
	return (new);
}
