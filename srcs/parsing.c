/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 13:19:03 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	showlst(t_list *list)
{
	while (list != NULL)
	{
		printf("list.word = %s\n", list->word);
		list = list->next;
	}
}

int	parsing_base(char *line, t_list **list)
{
	if (ft_lst_split(list, line, ' ') == -1)
		return (-1);
	return (0);
}
