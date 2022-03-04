/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_utils_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:09:31 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 19:27:31 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	var_del(char c, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_var(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '$' && line[i + 1]
		&& (line[i + 1] == '?' || line[i + 1] == '{'))
		return (1);
	if (line[i] == '$' && line[i + 1]
		&& !var_del(line[i + 1], " ,.?/][}+=-*%$#@!\'\"\0"))
		return (1);
	return (0);
}

int	var_cmp(char c, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_var(char *line)
{
	int	i;

	i = 1;
	if (line[i] == '?')
		return (2);
	if (line[i] == '{')
	{
		while (line[i] && line[i] != '}')
			i++;
		if (line[i])
			return (i + 1);
		return (i);
	}
	i++;
	while (line[i] && !var_del(line[i], " ,.?/][{}+=-*%$#@!|<>\'\"\0"))
		i++;
	return (i);
}
