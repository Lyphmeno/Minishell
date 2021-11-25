/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:31:05 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 14:35:31 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lstlen(t_start *start)
{
	int		nb;
	t_elem	*tmp;

	if (start->first == NULL)
		return (0);
	nb = 1;
	tmp = start->first;
	while (tmp->next != NULL)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}
