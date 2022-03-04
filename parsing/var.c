/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:47:31 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 19:39:10 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*rep(char *line, t_env **env)
{
	char	*tmp;
	int		len;

	len = get_tmplen(line, env);
	tmp = ft_calloc(sizeof(char), (len + 1));
	fill_tmp(line, tmp, env);
	if (line)
		free(line);
	if (tmp[0] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	return (tmp);
}

char	**var(char **linetab, t_env **env)
{
	int	i;
	int	j;
	int	tmp[3];

	i = 0;
	tmp[0] = 0;
	tmp[1] = 1;
	tmp[2] = 0;
	while (linetab[i])
	{
		j = 0;
		while (linetab[i] && linetab[i][j])
		{
			if (tmp[0] == 0 && linetab[i][j] && is_var(&linetab[i][j]))
				linetab[i] = rep(linetab[i], env);
			if (linetab[i] == NULL)
				tmp[2] = 1;
			if (linetab[i])
				j += var_loop(&linetab[i][j], env, tmp);
		}
		i++;
	}
	return (delempty(linetab, tmp[2]));
}
