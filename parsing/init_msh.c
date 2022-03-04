/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:53:20 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 19:14:43 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	add_cmd(t_msh **msh, t_msh *tmpmsh)
{
	t_msh	*index;

	if (*msh == NULL)
	{
		tmpmsh->next = NULL;
		tmpmsh->prev = NULL;
		*msh = tmpmsh;
	}
	else
	{
		index = *msh;
		while (index->next != NULL)
			index = index->next;
		tmpmsh->next = NULL;
		index->next = tmpmsh;
		tmpmsh->prev = index;
	}
}

int	get_rerror(char **linetab)
{
	int	i;

	i = 0;
	while (linetab[i] && linetab[i][0] != '|')
	{
		if ((linetab[i][0] == '>' || linetab[i][0] == '<')
			&& (!linetab[i + 1] || linetab[i + 1][0] == '|'))
			return (1);
		i++;
	}
	return (0);
}

void	fill_cmd(char **linetab, char **cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (linetab[i] && linetab[i][0] != '|')
	{
		if (!is_sep(linetab[i][0]) && !is_file(&linetab[i], i))
		{
			cmd[j] = ft_strdup(linetab[i]);
			j++;
		}
		i++;
	}
}

int	get_argnb(char **linetab)
{
	int	i;
	int	argnb;

	i = 0;
	argnb = 0;
	while (linetab[i] && linetab[i][0] != '|')
	{
		if (!is_sep(linetab[i][0]) && !is_file(&linetab[i], i))
			argnb++;
		i++;
	}
	return (argnb);
}
