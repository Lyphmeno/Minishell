/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:25:57 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 14:26:23 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_lst_add_front(t_elem *elem, t_start *start)
{
	if (start->first == NULL)
		start->first = elem;
	else
	{
		elem->next = start->first;
		start->first = elem;
	}
}
