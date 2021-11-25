/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:44:30 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 16:24:09 by jchene           ###   ########.fr       */
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
			printf("v[%d]:%s ----> %s\n", i, tmp->word, tmp->next->word);
			tmp = tmp->next;
			i++;
		}
		printf("v[%d]:%s ----> NULL\n", i, tmp->word);
	}
	printf("-----------------------------------------\n\n");
}
