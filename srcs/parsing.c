/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/07 17:49:43 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	parsing_base(void)
{
	if (line_split(st_mini()->line, ' ') == -1)
		return (-1);
	else
		ft_lst_show(st_words());
	
	if (!ft_lstlen(st_words()))
		return (0);
	ft_lst_free(st_words());
	return (0);
}
