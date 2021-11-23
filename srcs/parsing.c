/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/23 14:23:14 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	split_quotes(t_msh *mini)
{
	mini->linetab = ft_split(mini->line, ' ');
}

void	parsing_base(t_msh *mini)
{
	int	i;

	i = 0;
	split_quotes(mini);
	while (mini->linetab[i] != NULL)
	{
		printf("%s\n", mini->linetab[i]);
		i++;
	}
}