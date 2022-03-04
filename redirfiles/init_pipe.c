/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:37:01 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:20:17 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	init_pipe(t_msh *msh)
{
	int	fd[2];

	if (msh->next == NULL)
		return ;
	if (pipe(fd) == -1)
	{
		ft_putendl_fd("minishell: pipe failed", 2);
		return ;
	}
	msh->pipeout = fd[1];
	msh->next->pipein = fd[0];
}
