/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:52:34 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/09 14:17:44 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (str != NULL)
		write(fd, str, ft_strlen(str));
}

void	ft_putendl_fd(char *str, int fd)
{
	if (str != NULL)
	{
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
}
