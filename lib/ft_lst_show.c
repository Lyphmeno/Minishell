/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:44:30 by jchene            #+#    #+#             */
/*   Updated: 2022/02/10 14:03:40 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_lst_show(t_start *start)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	printf("-----------------------------------------\n");
	tmp = start->first;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			printf("v[%d]:%p|%s ----> %p|%s\n", i, &tmp->word,
				tmp->word, &tmp->next->word, tmp->next->word);
			tmp = tmp->next;
			i++;
		}
		printf("v[%d]:%p|%s ----> NULL\n", i, &tmp->word, tmp->word);
	}
	printf("-----------------------------------------\n\n");
}
