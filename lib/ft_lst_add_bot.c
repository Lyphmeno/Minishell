/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_bot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:29:40 by jchene            #+#    #+#             */
/*   Updated: 2022/03/01 13:08:45 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_lst_add_bot(t_list **list, char *word)
{
	t_list	*tmp;
	t_list	*new;

	new = (t_list *)ft_calloc(sizeof(t_list), 1);
	new->word = word;
	new->next = NULL;
	if (*list == NULL)
	{
		new->prev = NULL;
		*list = new;
	}
	else
	{
		tmp = *list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}
