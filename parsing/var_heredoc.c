/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:18:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/04 00:46:36 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*add_quotes(char *line)
{
	char	*lineres;
	int		i;
	int		j;

	i = 0;
	j = 1;
	lineres = ft_calloc(sizeof(char), ft_strlen(line) + 3);
	lineres[0] = '\'';
	while (line[i])
	{
		lineres[j] = line[i];
		i++;
		j++;
	}
	lineres[j] = '\'';
	j++;
	lineres[j] = '\0';
	free(line);
	return (lineres);
}

char	*add_doc(char **linetab, int num, int len)
{
	char	*lineres;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	lineres = ft_calloc(sizeof(char), (num + len + 1));
	while (linetab[++i])
	{
		j = -1;
		while (linetab[i][++j])
		{
			lineres[k] = linetab[i][j];
			k++;
		}
		if (linetab[i])
			lineres[k] = ' ';
		k++;
	}
	lineres[k] = '\0';
	free_twochar(linetab);
	return (lineres);
}

char	*var_heredoc(char *line)
{
	char	**linetab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	linetab = splitline(line);
	while (linetab[i])
	{
		if (i > 0 && ft_strcmp(linetab[i - 1], "<<") == 0)
		{
			linetab[i] = add_quotes(linetab[i]);
			j += 2;
		}
		i++;
	}
	i = 0;
	while (linetab[i])
	{
		j += ft_strlen(linetab[i]);
		i++;
	}
	free(line);
	return (add_doc(linetab, i, j));
}
