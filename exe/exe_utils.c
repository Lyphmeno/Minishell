/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:39:06 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/28 12:02:30 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_dir(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir != NULL)
	{
		closedir(dir);
		return (1);
	}
	return (0);
}

void	error_msg(char *arg, char *msg)
{
	char	*true_msg;

	true_msg = ft_strjoins("minishell: ", arg, msg);
	ft_putendl_fd(true_msg, 2);
	free(true_msg);
}
