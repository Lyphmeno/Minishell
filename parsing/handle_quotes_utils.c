/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:16:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 18:20:16 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	closed_quotes(char *line)
{
	int		i;
	char	c;

	c = line[0];
	i = 1;
	while (line[i] && line[i] != c)
		i++;
	if (!line[i])
		return (0);
	return (1);
}

int	contain_no_quotes(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			return (0);
		i++;
	}
	return (1);
}

int	nosp_len(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && len != 0)
			len++;
		while (line[i] && line[i] != ' ')
		{
			i++;
			len++;
		}
	}
	return (len);
}

void	nosp_fill(char *nosp, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && j != 0)
		{
			nosp[j] = ' ';
			j++;
		}
		while (line[i] && line[i] != ' ')
		{
			nosp[j] = line[i];
			i++;
			j++;
		}
	}
}

char	*nosp(char *line)
{
	char	*nosp;

	nosp = ft_calloc(sizeof(char), (nosp_len(line) + 1));
	if (!nosp)
	{
		free(line);
		return (NULL);
	}
	nosp_fill(nosp, line);
	free(line);
	return (nosp);
}
