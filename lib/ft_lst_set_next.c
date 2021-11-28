/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_set_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:03:46 by jchene            #+#    #+#             */
/*   Updated: 2021/11/28 16:09:10 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lst_set_next(t_elem *elem, t_elem *previous, t_start *lst)
{
	elem->next = previous->next;
	elem->prev = previous;
	previous->next->prev = elem;
	previous->next = elem;
	return (0);
}
