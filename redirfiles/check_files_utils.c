/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:45:24 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:51:57 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_outfile_fd(char *name)
{
	int	fd;

	fd = open(name, O_WRONLY | O_APPEND | O_CREAT,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	return (fd);
}

int	get_fd(t_msh *msh, char *name)
{
	while (msh != NULL)
	{
		if (already_open_file(msh->outfile, name) == 1)
			return (get_outfile_fd(name));
		msh = msh->prev;
	}
	return (0);
}

int	already_open_file(t_file *file, char *name)
{
	while (file != NULL)
	{
		if (file->type == APPEND || file->type == REPLACE)
			if (ft_strcmp(name, file->name) == 0 && access(name, F_OK) == 0)
				return (1);
		file = file->next;
	}
	return (0);
}

int	already_open(t_msh *msh, char *name)
{
	msh = msh->prev;
	while (msh != NULL)
	{
		if (msh->outfile != NULL)
			if (already_open_file(msh->outfile, name) == 1)
				return (1);
		msh = msh->prev;
	}
	return (0);
}
