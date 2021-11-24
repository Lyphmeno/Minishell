/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/24 18:56:12 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	parsing_base(void)
{
	ft_lst_split(st_mini()->line, ' ');
	ft_lst_show(st_words());
	if (!ft_lstlen(st_words()))
		return ;
	ft_lst_join();
	ft_lst_free(st_words());
}
