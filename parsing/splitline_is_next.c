/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitline_is_next.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:49:05 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 15:51:37 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_sep(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	next_word(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i])
		return (1);
	return (0);
}
