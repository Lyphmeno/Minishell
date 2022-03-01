/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:40:57 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/28 22:33:53 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_msh(t_msh *msh)
{
	int	i;

	i = 0;
	free(msh->cmd);
	while (i < msh->argnb)
	{
		free(msh->arg[i]);
		i++;
	}
	free(msh->arg);
	free(msh);
}
