/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 17:02:33 by jchene            #+#    #+#             */
/*   Updated: 2021/11/27 19:46:05 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//Count occurences of char c in char *str
int	ft_count_occur(char *str, char c)
{
	int	occur_nb;
	int	i;

	occur_nb = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			occur_nb++;
		i++;
	}
	return (occur_nb);
}
