/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:28:48 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 14:35:32 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	**ft_newarray(size_t w, size_t h, size_t size)
{
	void	**array_ptr;
	char	*array_byte;
	size_t	total_size;
	size_t	y;

	if (w == 0 || h == 0 || size == 0)
		return (NULL);
	total_size = (h * sizeof(void *)) + (w * h * size);
	if ((total_size - h * sizeof(void *)) != (w * h * size))
		return (NULL);
	array_ptr = (void **)malloc(total_size);
	array_byte = (char *)array_ptr + h * sizeof(void *);
	y = 0;
	while (y < h)
	{
		array_ptr[y] = array_byte + (y * (w * size));
		y++;
	}
	return (array_ptr);
}
