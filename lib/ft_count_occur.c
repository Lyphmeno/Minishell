/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_occur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 11:30:52 by jchene            #+#    #+#             */
/*   Updated: 2022/01/29 18:15:26 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_count_occur(char *word, char c)
{
	int	occur;
	int	i;

	i = 0;
	occur = 0;
	while (word[i])
	{
		if (word[i] == c)
			occur++;
		i++;
	}
	return (occur);
}
