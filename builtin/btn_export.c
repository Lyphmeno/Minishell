/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:20:09 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/19 13:26:21 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_syntax(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		if (src[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	btn_export(char *src, t_env **env)
{
	char	*key;
	char	*value;

	if (check_syntax(src) == 0)
		return ;
	key = get_key(src);
	value = get_value(src);
	btn_unset(key, env);
	add_env(key, value, env);
}
