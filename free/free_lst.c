/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:40:57 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/28 22:11:03 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_lst(t_list *list)
{
	t_list	*tmp;

	if (list == NULL)
		return ;
	while (list->prev != NULL)
		list = list->prev;
	while (list != NULL)
	{
		tmp = list->next;
		if (list->word != NULL)
			free(list->word);
		free(list);
		list = tmp;
	}
}
