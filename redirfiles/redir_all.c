/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:47:37 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 21:27:46 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_rerror(t_msh *msh)
{
	if (msh->rerror == 1)
	{
		ft_putendl_fd("minishell: ambiguous redirect", 2);
		g_exit = 1;
		return (1);
	}
	return (0);
}

void	close_fd_redir(t_msh *msh)
{
	if (msh->prev != NULL)
		close(msh->prev->pipeout);
	if (msh->next != NULL)
		close(msh->next->pipein);
	if (msh->infile != NULL)
		if (msh->infile->type != PIPE && msh->prev != NULL)
			close(msh->pipein);
	if (msh->outfile != NULL)
		if (msh->outfile->type != PIPE && msh->next != NULL)
			close(msh->pipeout);
}

void	redirect_input(t_msh *msh)
{
	if (msh->infile != NULL)
	{
		if (msh->infile->type == PIPE)
		{
			dup2(msh->pipein, STDIN_FILENO);
			close(msh->pipein);
		}
		else if (msh->input != 0)
		{
			dup2(msh->input, STDIN_FILENO);
			close(msh->input);
		}
	}
	else if (msh->input != 0)
	{
		dup2(msh->input, STDOUT_FILENO);
		close(msh->input);
	}
}

void	redirect_output(t_msh *msh)
{
	if (msh->outfile != NULL)
	{
		if (msh->outfile->type == PIPE)
		{
			dup2(msh->pipeout, STDOUT_FILENO);
			close(msh->pipeout);
		}
		else if (msh->output != 1)
		{
			dup2(msh->output, STDOUT_FILENO);
			close(msh->output);
		}
	}
	else if (msh->output != 1)
	{
		dup2(msh->output, STDOUT_FILENO);
		close(msh->output);
	}
}

void	redir(t_msh *msh)
{
	close_fd_redir(msh);
	redirect_input(msh);
	redirect_output(msh);
}
