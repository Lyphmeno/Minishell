/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:30:35 by hlevi             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/23 16:01:41 by jchene           ###   ########.fr       */
=======
/*   Updated: 2021/11/23 16:05:40 by hlevi            ###   ########.fr       */
>>>>>>> hugo
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	parsing_base(void)
{
<<<<<<< HEAD
	int		i;
	t_msh	*cc;
=======
	int	i;
>>>>>>> hugo

	cc = s_mini();
	i = 0;
<<<<<<< HEAD
	cc->linetab = ft_split(cc->line, ' ');
	while (cc->linetab[i] != NULL)
	{
		printf("%s\n", cc->linetab[i]);
=======
	s_mini()->linetab = ft_split(s_mini()->line, ' ');
	while (s_mini()->linetab[i] != NULL)
	{
		printf("%s\n", s_mini()->linetab[i]);
>>>>>>> hugo
		i++;
	}
}
