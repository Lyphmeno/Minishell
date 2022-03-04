/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:09:56 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:11:19 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	not_sp(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	btn_echo_redir(t_msh *msh, int fd, int nl)
{
	int	i;

	i = 1;
	while (nl == 1 && msh->cmd[i] && check_nl_echo(msh->cmd[i]))
		i++;
	while (msh->cmd[i] != NULL)
	{
		ft_putstr_fd(msh->cmd[i], fd);
		if (msh->cmd[i + 1] != NULL && not_sp(msh->cmd[i]))
			ft_putchar_fd(' ', fd);
		i++;
	}
	if (nl == 0)
		ft_putchar_fd('\n', fd);
	return (0);
}

int	btn_echo(t_msh *msh, int nl)
{
	int	i;

	i = 1;
	while (nl == 1 && msh->cmd[i] && check_nl_echo(msh->cmd[i]))
		i++;
	while (msh->cmd[i] != NULL)
	{
		ft_putstr_fd(msh->cmd[i], 1);
		if (msh->cmd[i + 1] != NULL && not_sp(msh->cmd[i]))
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (nl == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}
