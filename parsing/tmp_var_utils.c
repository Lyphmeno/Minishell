/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_var_utils.C                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:12:41 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 17:25:50 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	var_len(char *line, int sp, t_env **env)
{
	int		i;
	int		len;
	char	*var;

	i = 0;
	len = 0;
	var = get_var(line, sp, env);
	if (!var)
		return (i);
	while (var[i])
	{
		while (var[i] == ' ' && var[i + 1] && var[i + 1] == ' ' && sp)
			i++;
		if (var[i])
		{
			i++;
			len++;
		}
	}
	free(var);
	return (i);
}

int	var_next(char *line, int *sp)
{
	int	i;
	int	nov;

	i = 0;
	nov = 0;
	while (line[i])
	{
		if (line[i] == '\'' && nov == 0 && *sp)
			nov = 1;
		else if (line[i] == '\'' && nov == 1 && *sp)
			nov = 0;
		if (line[i] == '\"' && *sp == 0 && !nov)
			*sp = 1;
		else if (line[i] == '\"' && *sp == 1 && !nov)
			*sp = 0;
		if (is_var(&line[i]) && nov == 0)
			return (i);
		else
			i++;
	}
	return (i);
}
