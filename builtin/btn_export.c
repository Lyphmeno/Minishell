/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:20:09 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/26 13:52:54 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_syntax(char *src)
{
	int	i;

	i = 1;
	if ((src[0] < 'a' || src[0] > 'z') && (src[0] < 'A'
			|| src[0] > 'Z') && src[0] != '_')
		return (1);
	while (src[i] != '\0')
	{
		if ((src[i] < 'a' || src[i] > 'z') && (src[i] < 'A'
				|| src[i] > 'Z') && (src[i] < '1'
				|| src[i] > '9') && src[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	btn_export(char *src, t_env **env)
{
	char	*key;
	char	*value;

	if (check_syntax(src) == 0)
		return (-1);
	key = get_key(src);
	value = get_value(src);
	btn_unset(key, env);
	add_env(key, value, env);
	return (0);
}
