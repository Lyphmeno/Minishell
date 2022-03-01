/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:40:42 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/10 14:22:59 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	btn_pwd(void)
{
	char	repo[MAX_PATH];

	if (!(getcwd(repo, MAX_PATH)))
		return (-1);
	printf("%s\n", repo);
	return (0);
}
