/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_get_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:21:19 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 17:36:04 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*varname_exit(void)
{
	char	*varname;

	varname = ft_calloc(sizeof(char), 2);
	if (!varname)
		return (NULL);
	varname[0] = '?';
	return (varname);
}

char	*get_varname(char *line)
{
	char	*varname;
	int		i;

	if (*line == '{')
		line++;
	if (*line == '?')
		return (varname_exit());
	i = 0;
	while (line[i] && !var_del(line[i], " ,.?/][}+=-*%$#@!|><\'\"\0"))
		i++;
	varname = ft_calloc(sizeof(char), (i + 1));
	if (!varname)
		return (NULL);
	i = 0;
	while (line[i] && !var_del(line[i], " ,.?/][}+=-*%$#@!|<>\'\"\0"))
	{
		varname[i] = line[i];
		i++;
	}
	return (varname);
}

char	*get_var(char *line, int sp, t_env **env)
{
	char	*varname;
	char	*res;

	varname = get_varname(line + 1);
	if (!varname)
		return (NULL);
	res = ft_strdup(get_env(varname, *env));
	if (res == NULL && !sp)
		res = ft_strdup("");
	else if (res == NULL)
		res = ft_strdup("");
	if (res && contain_quote(res))
		res = quote_res(res);
	if (res && (res[0] == '>' || res[0] == '<' || res[0] == '|') && sp)
		res = quote_res(res);
	free(varname);
	return (res);
}
