/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:58:05 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 19:38:39 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	check_loop_quotes(char c, int *tmp)
{
	if (c == '\'' && tmp[0] == 0 && tmp[1] == 1)
		tmp[0] = 1;
	else if (c == '\'' && tmp[0] == 1 && tmp[1] == 1)
		tmp[0] = 0;
	if (c == '\"' && tmp[1] == 1 && tmp[0] == 0)
		tmp[1] = 0;
	else if (c == '\"' && tmp[1] == 0 && tmp[0] == 0)
		tmp[1] = 1;
}


int	is_loop(char *key, char *value)
{
	int	i;
	int	j;

	i = 0;
	while (value[i])
	{
		j = 0;
		while (key[j] && value[i + j] && key[j] == value[i + j])
			j++;
		if (!key[j])
			return (1);
		i++;
	}
	return (0);
}

int	var_loop(char *line, t_env **env, int *tmp)
{
	int		i;
	char	*res;
	char	*varname;

	i = 0;
	while (line[i] && (!is_var(&line[i]) || tmp[0] == 1))
	{
		check_loop_quotes(line[i], tmp);
		i++;
	}
	if (line[i] && is_var(&line[i]) && tmp[0] == 0)
	{
		varname = get_varname(&line[i] + 1);
		res = get_var(&line[i], tmp[1], env);
		if (is_loop(varname, res))
		{
			free(res);
			free(varname);
			return (i + check_var(&line[i]));
		}
		free(res);
		free(varname);
		return (i);
	}
	return (i);
}
