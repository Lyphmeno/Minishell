/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_count_occur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:10:14 by jchene            #+#    #+#             */
/*   Updated: 2021/11/26 21:33:43 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

//Count occurences of char c in every char * of list lst
int	ft_lst_count_occur(t_start *lst, char c)
{
	int		quotes_nb;
	t_elem	*tmp;

	quotes_nb = 0;
	tmp = lst->first;
	if (!tmp)
		return (0);
	while (tmp->next)
	{
		if (ft_charset(tmp->word, '"'))
			quotes_nb++;
		tmp = tmp->next;
	}
	return (quotes_nb);
}
