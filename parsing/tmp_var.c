/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:09:46 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:53:01 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	novar_fill(char *line, char *tmp, int *sp)
{
	int	i;
	int	novar;

	i = 0;
	novar = 0;
	while (line[i])
	{
		if (line[i] == '\'' && novar == 0 && *sp)
			novar = 1;
		else if (line[i] == '\'' && novar == 1 && *sp)
			novar = 0;
		if (line[i] == '\"' && *sp == 0 && !novar)
			*sp = 1;
		else if (line[i] == '\"' && *sp == 1 && !novar)
			*sp = 0;
		if (is_var(&line[i]) && novar == 0)
			return (i);
		else
		{
			tmp[i] = line[i];
			i++;
		}
	}
	return (i);
}

int	get_tmplen(char *line, t_env **env)
{
	int	i;
	int	sp;
	int	add;
	int	llen;

	i = 0;
	llen = 0;
	sp = 1;
	while (line[i])
	{
		add = var_next(&line[i], &sp);
		i += add;
		llen += add;
		if (line[i])
		{
			llen += var_len(&line[i], sp, env);
			i += check_var(&line[i]);
		}
	}
	return (llen);
}

int	tmpadd(char *line, char *tmp, int sp, t_env **env)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	var = get_var(line, sp, env);
	if (!var)
		return (0);
	while (var[i])
	{
		while (var[i] == ' ' && var[i + 1] && var[i + 1] == ' ' && sp)
			i++;
		if (var[i])
		{
			tmp[j] = var[i];
			i++;
			j++;
		}
	}
	tmp[j] = '\0';
	free(var);
	return (i);
}

void	fill_tmp(char *line, char *tmp, t_env **env)
{
	int	i;
	int	j;
	int	sp;
	int	add;

	i = 0;
	j = 0;
	sp = 1;
	add = 0;
	while (line[i])
	{
		add = novar_fill(&line[i], &tmp[j], &sp);
		i += add;
		j += add;
		if (line[i])
		{
			j += tmpadd(&line[i], &tmp[j], sp, env);
			i += check_var(&line[i]);
		}
	}
}
