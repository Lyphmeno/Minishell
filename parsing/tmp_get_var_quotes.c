/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_get_var_quotes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:37:08 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 17:41:40 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	contain_quote(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i])
	{
		if (line[i] == '\'' || line[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

void	fill_quote_res(char *line, char *res, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	if (c == '\'')
		res[0] = '\"';
	else
		res[0] = '\'';
	while (line[i])
	{
		res[j] = line[i];
		i++;
		j++;
	}
	if (c == '\'')
		res[j] = '\"';
	else
		res[j] = '\'';
	j++;
	res[j] = '\0';
}

char	*quote_res(char *line)
{
	int		i;
	char	c;
	char	*res;

	i = 0;
	if (!line)
		return (NULL);
	res = ft_calloc(sizeof(char), (ft_strlen(line) + 3));
	if (!res)
	{
		free(line);
		return (NULL);
	}
	while (line[i] && line[i] != '\'' && line[i] != '\"')
		i++;
	if (!line[i])
		c = '\"';
	c = line[i];
	fill_quote_res(line, res, c);
	free(line);
	return (res);
}
