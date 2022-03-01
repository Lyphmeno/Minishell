/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 19:09:31 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 19:11:47 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_var(char *line)
{
	int	i;

	i = 0;
	if (line[i] == '$' && line[i + 1]
		&& (line[i + 1] == '?' || line[i + 1] == '{'))
		return (1);
	if (line[i] == '$' && line[i + 1]
		&& !ft_is_vardel(line[i + 1], " ,.?/][}+=-*%$#@!\'\"\0"))
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
