/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:09:56 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/14 18:56:30 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	btn_echo(t_msh *msh, int nl)
{
	int		i;

	i = 0;
	if (nl != 0)
		i = 1;
	while (msh->arg[i] != NULL)
	{
		ft_putstr_fd(msh->arg[i], 1);
		if (msh->arg[i +1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (nl == 0)
		write(1, "\n", 1);
}
