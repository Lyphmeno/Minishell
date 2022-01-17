/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:25:57 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 14:35:27 by hlevi            ###   ########.fr       */
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
