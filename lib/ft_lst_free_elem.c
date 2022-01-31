/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 02:10:40 by jchene            #+#    #+#             */
/*   Updated: 2021/11/29 16:31:59 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_lst_free_elem(t_elem *elem, t_start *lst)
{
	t_elem	*tmp_prev;
	t_elem	*tmp_next;

	tmp_prev = NULL;
	tmp_next = NULL;
	if (elem->prev)
		tmp_prev = elem->prev;
	if (elem->next)
		tmp_next = elem->next;
	free(elem->word);
	free(elem);
	if (tmp_prev)
		tmp_prev->next = tmp_next;
	else
		lst->first = tmp_next;
	if (tmp_next)
		tmp_next->prev = tmp_prev;
}
