/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/19 01:00:29 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	parsing_base(t_msh *mini)
{
	int	i;

	i = 0;
	mini->linetab = ft_split(mini->line, ' ');
	while (mini->linetab[i] != NULL)
	{
		printf("%s\n", mini->linetab[i]);
		i++;
	}
}
