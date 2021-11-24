/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_last_elem.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:26:48 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 14:26:52 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_elem	*last_elem(t_start *start)
{
	t_elem	*tmp;

	if (start->first == NULL)
		return (start->first);
	tmp = start->first;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
