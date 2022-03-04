/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:53:03 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:49:18 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_exe(t_env *env, t_msh *msh)
{
	free_env(env);
	free_msh(msh);
	rl_clear_history();
}

void	free_all(t_env *env, t_msh *msh)
{
	close(0);
	close(1);
	close(2);
	msh = msh->prev;
	while (msh != NULL)
	{
		if (msh->input != 0)
			close(msh->input);
		if (msh->output != 1)
			close(msh->output);
		msh = msh->prev;
	}
	free_env(env);
	free_msh(msh);
	rl_clear_history();
}
