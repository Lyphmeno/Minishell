/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:40:52 by jchene            #+#    #+#             */
/*   Updated: 2021/11/26 22:02:08 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lst_join(void)
{
	t_elem	*open_word;
	t_elem	*close_word;
	t_elem	*tmp;

	close_word = NULL;
	tmp = st_words()->first;
	if (!tmp)
		return (0);
	if (((ft_lst_count_occur(st_words(), '"')) % 2) != 0)
		return (-1);
	while (tmp->next)
	{
		open_word = ft_lst_next_occur(tmp)
	}
	//Travail en cours ici
	/*if (!open_word)
		open_word = tmp;
	else if (!close_word)
		close_word = tmp;*/
	return (0);
}
