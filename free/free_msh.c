/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_msh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:40:57 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:50:10 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	free_file(t_file *file)
{
	t_file	*tmp;

	if (file == NULL)
		return ;
	while (file->prev)
		file = file->prev;
	while (file != NULL)
	{
		tmp = file->next;
		if (file->name != NULL)
			free(file->name);
		free(file);
		file = tmp;
	}
}

void	free_msh(t_msh *msh)
{
	t_msh	*tmp;

	if (msh == NULL)
		return ;
	while (msh->prev != NULL)
		msh = msh->prev;
	while (msh != NULL)
	{
		tmp = msh->next;
		if (msh->cmd != NULL)
			free_twochar(msh->cmd);
		if (msh->infile != NULL)
			free_file(msh->infile);
		if (msh->outfile != NULL)
			free_file(msh->outfile);
		free(msh);
		msh = tmp;
	}
}
