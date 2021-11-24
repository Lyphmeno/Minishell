/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:40:52 by jchene            #+#    #+#             */
/*   Updated: 2021/11/24 21:07:15 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lst_join(void)
{
	t_elem	*open_word;
	t_elem	*close_word;
	t_elem	*tmp;
	int		quotes_nb;

	open_word = NULL;
	close_word = NULL;
	tmp = st_words()->first;
	quotes_nb = 0;
	if (!tmp)
		return (0);
	quotes_nb = ft_lst_count_occur(st_words(), '"');
	if ((quotes_nb % 2) != 0)
		return (-1);
	//Travail en cours ici
	/*if (!open_word)
		open_word = tmp;
	else if (!close_word)
		close_word = tmp;*/
	return (0);
}