/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:19:57 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 19:15:31 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	quotes_error(char **linetab)
{
	int	i;
	int	j;

	i = 0;
	while (linetab[i])
	{
		j = 0;
		while (linetab[i][j])
		{
			while (linetab[i][j] && linetab[i][j] != '\"'
				&& linetab[i][j] != '\'')
				j++;
			if (!linetab[i][j])
				break ;
			if (!closed_quotes(&linetab[i][j]))
				return (1);
			j += check_quotes(&linetab[i][j]);
		}
		i++;
	}
	return (0);
}

int	endsep_error(char **linetab)
{
	int	i;

	i = 0;
	while (linetab[i] && linetab[i + 1])
		i++;
	if (linetab[i] && (linetab[i][0] == '<' || linetab[i][0] == '>'
			|| linetab[i][0] == '|'))
		return (1);
	return (0);
}

int	endpipecmd_error(char **linetab)
{
	int	i;

	i = 0;
	while (linetab[i] && linetab[i + 1])
	{
		if (!is_file(&linetab[i], i) && !is_sep(linetab[i][0]))
			return (0);
		i++;
	}
	if (linetab[i] && linetab[i][0] == '|')
		return (1);
	return (0);
}

int	sep_error(char **linetab)
{
	int	i;

	i = 0;
	while (linetab[i])
	{
		if ((linetab[i][0] == '<' || linetab[i][0] == '>') && linetab[i + 1]
			&& is_sep(linetab[i + 1][0]))
			return (1);
		if (linetab[i][0] == '|' && linetab[i + 1]
			&& linetab[i + 1][0] == '|')
			return (1);
		i++;
	}
	return (0);
}

int	parsing_error(char **linetab)
{
	if (sep_error(linetab))
	{
		ft_putendl_fd("minishell: syntax error 1", 2);
		return (1);
	}
	if (endpipecmd_error(linetab))
	{
		ft_putendl_fd("minishell: syntax error 2", 2);
		return (1);
	}
	if (endsep_error(linetab))
	{
		ft_putendl_fd("minishell: syntax error 3", 2);
		return (1);
	}
	if (quotes_error(linetab))
	{
		ft_putendl_fd("minishell: syntax error 4", 2);
		return (1);
	}
	return (0);
}
