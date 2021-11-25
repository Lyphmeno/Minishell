/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/24 14:38:00 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	parsing_base(void)
{
	int	i;

	i = 0;
	st_mini()->linetab = ft_split(st_mini()->line, ' ');
	ft_lst_split(st_mini()->line, ' ');
	while (st_mini()->linetab[i] != NULL)
	{
		printf("%s\n", st_mini()->linetab[i]);
		i++;
	}
}
