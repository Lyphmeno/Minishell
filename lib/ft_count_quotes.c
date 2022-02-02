/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:56:30 by jchene            #+#    #+#             */
/*   Updated: 2022/02/02 12:49:29 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_count_quotes(char *str, char c)
{
	int	open_d;
	int open_s;
	int i;
	int	nb;

	open_d = 0;
	open_s = 0;
	i = 0;
	nb = 0;
	while (str[i])
	{
		if (str[i] == '"' && open_s == 0)
		{
			open_d = (open_d - 1) * -1;
			if (c == '"')
				nb++;
		}
		else if (str[i] == '\'' && open_d == 0)
		{
			open_s = (open_s - 1) * -1;
			if (c == '\'')
				nb++;
		}
		i++;
	}
	return (nb);
}