/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 18:53:07 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/04 01:04:54 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_msh	*parsing_exit(char **strtab)
{
	g_exit = 2;
	free_twochar(strtab);
	return (NULL);
}

int	var_error_check(char *line)
{
	int	i;

	i = 1;
	if (line[i] != '{')
		return (0);
	i++;
	while (line[i] && line[i] != '}')
	{
		if (var_cmp(line[i], " \'\"\\][@$&*().|><"))
			return (1);
		i++;
	}
	if (!line[i])
		return (1);
	return (0);
}

int	var_error(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (line[i])
	{
		while (line[i] && !(is_var(&line[i])))
		{
			if (line[i] == '\'')
				j *= -1;
			i++;
		}
		if (line[i] && j == 1)
		{
			if (var_error_check(&line[i]))
			{
				ft_putendl_fd("minishell: syntax error", 2);
				return (1);
			}
		}
		if (line[i])
			i++;
	}
	return (0);
}

t_msh	*parse_all(char *line, t_env **env)
{
	t_msh	*msh;
	char	**linetab;
	char	**new;
	char	*ext_code;

	msh = NULL;
	ext_code = ft_itoa(g_exit);
	set_env("?", ext_code, *env);
	free(ext_code);
	if (var_error(line))
	{
		free(line);
		return (NULL);
	}
	line = var_heredoc(line);
	linetab = splitline(line);
	free(line);
	if (parsing_error(linetab))
		return (parsing_exit(linetab));
	new = var(linetab, env);
	handle_quotes(new);
	msh = handle_msh(new);
	free_twochar(new);
	return (msh);
}
