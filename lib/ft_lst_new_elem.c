/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:29:43 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 14:35:30 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lst_new_elem(char *word, t_start *start)
{
	t_elem	*elem;

	elem = malloc(sizeof(t_elem));
	if (!elem)
		return (-1);
	elem->word = word;
	elem->next = NULL;
	ft_lst_add_bot(elem, start);
	return (0);
}
