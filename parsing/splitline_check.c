/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitline_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:35:28 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/04 00:46:17 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_quotes_utils(char *line)
{
	char	c;
	int		i;

	if (!closed_quotes(line))
		return (check_word(line));
	i = 1;
	c = line[0];
	while (line[i] && line[i] != c)
		i++;
	if (!line[i])
		return (i);
	return (i + 1);
}

int	check_quotes(char *line)
{
	int	i;

	i = 0;
	i += check_quotes_utils(&line[i]);
	if (line[i] && line[i] != ' ' && !is_sep(line[i]))
		return (i + check_word(&line[i]));
	else
		return (i);
}

int	check_sep(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '>' && line[i + 1] == '>')
		return (2);
	if (line[i] == '<' && line[i + 1] == '<')
		return (2);
	return (1);
}

int	check_word(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (is_sep(line[i]))
		return (i + check_sep(&line[i]));
	if ((line[i] == '\'' || line[i] == '\"') && closed_quotes(&line[i]))
		return (i + check_quotes(&line[i]));
	while (line[i] && line[i] != ' ' && !is_sep(line[i]))
	{
		if ((line[i] == '\'' || line[i] == '\"') && closed_quotes(&line[i]))
			i += check_quotes(&line[i]);
		if (line[i] && line[i] != ' ' && !is_sep(line[i]))
			i++;
	}
	return (i);
}
