/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count_occur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:10:14 by jchene            #+#    #+#             */
/*   Updated: 2021/11/27 17:07:39 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//Count occurences of char c in every char * of list lst
int	ft_lst_count_occur(t_start *lst, char c)
{
	int		occur_nb;
	t_elem	*tmp;

	occur_nb = 0;
	tmp = lst->first;
	if (!tmp)
		return (0);
	while (tmp)
	{
		occur_nb += ft_count_occur(tmp->word, c);
		tmp = tmp->next;
	}
	return (occur_nb);
}
