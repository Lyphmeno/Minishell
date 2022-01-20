/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_btn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:11:11 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/20 14:28:13 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_btn(char *arg)
{
	if (ft_strcmp(arg, "echo") == 0 || ft_strcmp(arg, "env") == 0
		|| ft_strcmp(arg, "exit") == 0 || ft_strcmp(arg, "export") == 0
		|| ft_strcmp(arg, "cd") == 0 || ft_strcmp(arg, "pwd") == 0
		|| ft_strcmp(arg, "unset") == 0)
		return (1);
	return (0);
}
