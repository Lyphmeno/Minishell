/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_bot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:29:40 by jchene            #+#    #+#             */
/*   Updated: 2021/11/27 20:09:48 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_lst_add_bot(t_elem *elem, t_start *start)
{
	if (start->first == NULL)
		start->first = elem;
	else
	{
		elem->prev = ft_lst_last_elem(start);
		ft_lst_last_elem(start)->next = elem;
	}
}
