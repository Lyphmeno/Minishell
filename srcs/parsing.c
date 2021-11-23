/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/23 16:01:41 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	parsing_base(void)
{
	int		i;
	t_msh	*cc;

	cc = s_mini();
	i = 0;
	cc->linetab = ft_split(cc->line, ' ');
	while (cc->linetab[i] != NULL)
	{
		printf("%s\n", cc->linetab[i]);
		i++;
	}
}
