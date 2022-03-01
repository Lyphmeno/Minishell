/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:55:52 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/10 13:56:08 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	ft_filtoa(char *num, unsigned int nbr, int n, unsigned int div)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		num[i] = '-';
		i++;
	}
	while (div > 0)
	{
		num[i] = nbr / div + '0';
		nbr = nbr % div;
		div /= 10;
		i++;
	}
	num[i] = '\0';
}

char	*ft_itoa(int n)
{
	unsigned int	div;
	int				size;
	char			*num;
	unsigned int	nbr;

	if (n < 0)
		nbr = (unsigned int)(-n);
	else
		nbr = (unsigned int)n;
	div = 1;
	size = 1;
	while (div <= nbr / 10)
	{
		div *= 10;
		size++;
	}
	if (n < 0)
		size++;
	num = malloc((size + 1) * sizeof(char));
	if (!num)
		return (NULL);
	ft_filtoa(num, nbr, n, div);
	return (num);
}
