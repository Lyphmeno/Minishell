/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:20:59 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:51:20 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*read_heredoc(t_file *file)
{
	char	*line;
	char	*heredoc;
	char	*tmp;

	line = readline("> ");
	heredoc = NULL;
	while (line != NULL)
	{
		if (ft_strcmp(line, file->name) == 0)
		{
			free(line);
			break ;
		}
		tmp = join_doc(heredoc, line);
		free(heredoc);
		heredoc = tmp;
		free(line);
		line = readline("> ");
	}
	return (heredoc);
}

void	write_heredoc(t_file *infile, int *fd)
{
	char	*heredoc;

	sighandler(3);
	close(fd[0]);
	heredoc = read_heredoc(infile);
	write(fd[1], heredoc, ft_strlen(heredoc));
	close(fd[1]);
	close(0);
	close(1);
	close(2);
	exit (0);
}

void	create_heredoc(t_file *infile, int mode, int *ext)
{
	char	*heredoc;
	int		fd[2];
	int		pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
		write_heredoc(infile, fd);
	else
	{
		close(fd[1]);
		waitpid(pid, ext, 0);
		heredoc = get_heredoc(fd[0]);
		close(fd[0]);
	}
	if (mode == 1)
		send_heredoc(heredoc, infile);
	else
		free(heredoc);
}

void	init_all_heredoc(t_file *infile, int *ext)
{
	while (infile != NULL)
	{
		if (infile->type == HEREDOC && infile->next == NULL)
			create_heredoc(infile, 1, ext);
		else if (infile->next != NULL)
		{
			if (infile->type == HEREDOC && infile->next->type == PIPE)
				create_heredoc(infile, 1, ext);
			else if (infile->type == HEREDOC && (infile->next->type == HEREDOC
					|| infile->next->type == INFILE))
				create_heredoc(infile, 0, ext);
		}
		infile = infile->next;
	}
}

int	init_heredoc(t_msh *msh, int *ext)
{
	int		status;
	t_file	*begin;
	t_msh	*tmpmsh;

	status = g_exit;
	g_exit = -1;
	tmpmsh = msh;
	while (msh != NULL)
	{
		begin = msh->infile;
		init_all_heredoc(msh->infile, ext);
		msh->infile = begin;
		msh = msh->next;
	}
	if (g_exit != 130)
	{
		g_exit = status;
		return (1);
	}
	destroy_heredoc(tmpmsh);
	return (0);
}
