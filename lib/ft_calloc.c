/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:48:08 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/24 14:24:15 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem == NULL)
		return (NULL);
	return (ft_memset(mem, 0, count * size));
}
