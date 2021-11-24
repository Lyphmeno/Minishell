/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/24 13:38:37 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"
 
void	parsing_base(void)
{
	int	i;

	i = 0;
	mini()->linetab = ft_split(mini()->line, ' ');
	while (mini()->linetab[i] != NULL)
	{
		printf("%s\n", mini()->linetab[i]);
		i++;
	}
}
