/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:31:05 by jchene            #+#    #+#             */
/*   Updated: 2022/02/28 22:57:29 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lstlen(t_list *list)
{
	int		nb;

	nb = 0;
	while (list->next != NULL)
	{
		nb++;
		list = list->next;
	}
	return (nb);
}
