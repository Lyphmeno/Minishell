/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:14:13 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 20:19:44 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	close_fd(t_msh *msh)
{
	if (msh->prev != NULL)
	{
		close(msh->pipein);
		close(msh->prev->pipeout);
	}
}

void	destroy_heredoc(t_msh *msh)
{
	int		fd;
	t_file	*begin;

	while (msh != NULL)
	{
		begin = msh->infile;
		while (msh->infile)
		{
			if (msh->infile->type == HEREDOC)
			{
				fd = open(msh->infile->name, O_RDONLY);
				if (fd != -1)
				{
					close(fd);
					unlink(msh->infile->name);
				}
			}
			msh->infile = msh->infile->next;
		}
		msh->infile = begin;
		msh = msh->next;
	}
}

void	close_all_files(t_msh *msh)
{
	while (msh != NULL)
	{
		if (msh->input != 0)
			close(msh->input);
		if (msh->output != 1)
			close(msh->output);
		msh = msh->next;
	}
}

void	close_all(t_msh *msh)
{
	close_all_files(msh);
	destroy_heredoc(msh);
}
