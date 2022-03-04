/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:42 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 22:00:48 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	btn_pwd_redir(t_msh *msh)
{
	char	repo[MAX_PATH];

	if (!(getcwd(repo, MAX_PATH)))
	{
		ft_putendl_fd("minishell: pwd: error retrieving current directory", 2);
		return (1);
	}
	ft_putendl_fd(repo, msh->output);
	return (0);
}

int	btn_pwd(void)
{
	char	repo[MAX_PATH];

	if (!(getcwd(repo, MAX_PATH)))
	{
		ft_putendl_fd("minishell: pwd: error retrieving current directory", 2);
		return (1);
	}
	ft_putendl_fd(repo, 1);
	return (0);
}
