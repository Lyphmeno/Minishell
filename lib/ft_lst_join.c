/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:40:52 by jchene            #+#    #+#             */
/*   Updated: 2021/11/29 02:14:24 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lst_join(void)
{
	t_elem	*open_word;
	t_elem	*close_word;
	t_elem	*tmp;

	tmp = st_words()->first;
	if (((ft_lst_count_occur(st_words(), '"')) % 2) != 0)
		return (-1);
	while (tmp)
	{
		while (tmp && ft_count_occur(tmp->word, '"') % 2 == 0)
			tmp = tmp->next;
		if (!tmp)
			break ;
		open_word = tmp;
		tmp = tmp->next;
		while (ft_charset(tmp->word, '"') == 0)
			tmp = tmp->next;
		close_word = tmp;
		ft_lst_elem_join(st_words(), open_word, close_word);
		tmp = tmp->next;
	}
	return (0);
}
