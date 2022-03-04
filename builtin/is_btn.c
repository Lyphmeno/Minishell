/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_btn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:11:11 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:04:23 by hlevi            ###   ########.fr       */
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

int	is_btn(char *arg)
{
	if (ft_strcmp(arg, "echo") == 0 || ft_strcmp(arg, "env") == 0
		|| ft_strcmp(arg, "exit") == 0 || ft_strcmp(arg, "export") == 0
		|| ft_strcmp(arg, "cd") == 0 || ft_strcmp(arg, "pwd") == 0
		|| ft_strcmp(arg, "unset") == 0)
		return (1);
	return (0);
}
