/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_bot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:29:40 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 14:35:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_lst_add_bot(t_elem *elem, t_start *start)
{
	if (start->first == NULL)
		start->first = elem;
	else
		ft_lst_last_elem(start)->next = elem;
}
