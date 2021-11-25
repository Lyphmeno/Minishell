/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:11:07 by jchene            #+#    #+#             */
/*   Updated: 2021/11/25 12:19:45 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_lst_free(t_start *start)
{
	int		len;
	t_elem	*last;

	len = ft_lstlen(start) - 1;
	last = ft_lst_last_elem(start);
	while (len-- > 0)
	{
		last = ft_lst_last_elem(start);
		ft_lst_before_last(start)->next = NULL;
		free(last);tag:"remote-menu"
	}
	free(start->first);
	start->first = NULL;
}
