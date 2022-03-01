/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_before_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:12:54 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 14:35:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_elem	*ft_lst_before_last(t_start *start)
{
	t_elem	*tmp;

	if (start->first == NULL)
		return (start->first);
	if (start->first->next == NULL)
		return (start->first);
	tmp = start->first;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
