/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:41:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:55:13 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static void	send_err_msg(char *name, char mode)
{
	char	*err_msg;

	if (mode == 'F')
		err_msg = ft_strjoins("minishell: ",
				name, ": No such file or directory");
	if (mode == 'P')
		err_msg = ft_strjoins("minishell: ", name, ": Permission denied");
	if (err_msg != NULL)
	{
		g_exit = 1;
		ft_putendl_fd(err_msg, 2);
		free(err_msg);
	}
}

int	stock_fd(int fd, t_msh *msh, t_file *outfile)
{
	if (fd == -1)
	{
		send_err_msg(outfile->name, 'P');
		return (0);
	}
	if (outfile->next == NULL)
		msh->output = fd;
	else
		close(fd);
	return (1);
}

int	check_infile(t_file *infile, t_msh *msh)
{
	int	fd;

	if (access(infile->name, F_OK) == -1 && infile->type != HEREDOC)
	{
		send_err_msg(infile->name, 'F');
		return (0);
	}
	if (access(infile->name, R_OK) == -1 && infile->type != HEREDOC)
	{
		send_err_msg(infile->name, 'p');
		return (0);
	}
	fd = open(infile->name, O_RDONLY);
	if (infile->type != HEREDOC && fd == -1)
	{
		send_err_msg(infile->name, 'p');
		return (0);
	}
	if (infile->next == NULL)
		msh->input = fd;
	else if (fd != -1)
		close(fd);
	return (1);
}

int	check_outfile(t_file *outfile, t_msh *msh)
{
	int	fd;

	if (already_open(msh, outfile->name) == 1)
		return (stock_fd(get_fd(msh, outfile->name), msh, outfile));
	if (access(outfile->name, F_OK) == 0)
	{
		if (access(outfile->name, W_OK) == -1)
		{
			send_err_msg(outfile->name, 'p');
			return (0);
		}
	}
	if (outfile->type == APPEND)
		fd = open(outfile->name, O_WRONLY | O_APPEND | O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (outfile->type == REPLACE)
		fd = open(outfile->name, O_WRONLY | O_TRUNC | O_CREAT,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (stock_fd(fd, msh, outfile));
}

int	check_files(t_file *infile, t_file *outfile, t_msh *msh)
{
	while (infile != NULL)
	{
		if (infile->type != PIPE)
			if (check_infile(infile, msh) == 0)
				return (0);
		infile = infile->next;
	}
	while (outfile != NULL)
	{
		if (outfile->type != PIPE)
			if (check_outfile(outfile, msh) == 0)
				return (0);
		outfile = outfile->next;
	}
	return (1);
}
