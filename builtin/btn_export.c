/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:20:09 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:16:52 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	check_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	check_syntax(char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0' && src[i] != '=')
	{
		if (!((src[i] >= 'a' && src[i] <= 'z') || (src[i] >= 'A'
					&& src[i] <= 'Z') || (src[i] == '_')))
		{
			error_export(src, ": not a valid identifier\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

void	valid_export(t_msh *msh, t_env **env, int i)
{
	char	*key;
	char	*value;

	key = get_key(msh->cmd[i]);
	value = get_value(msh->cmd[i]);
	if (get_env_index(key, *env) == -1)
		add_env(key, value, env);
	else
		set_env(key, value, *env);
	free(key);
	free(value);
}

int	btn_export_redir(t_msh *msh, t_env **env)
{
	int		i;
	int		ext;

	i = 1;
	ext = 0;
	if (!msh->cmd[1])
	{
		btn_export_empty(*env, msh->output);
		return (ext);
	}
	while (msh->cmd[i])
	{
		if (check_syntax(msh->cmd[i]) == -1)
		{
			ext = 1;
		}
		else if (check_format(msh->cmd[i]) != 0)
			valid_export(msh, env, i);
		i++;
	}
	return (ext);
}

int	btn_export(t_msh *msh, t_env **env)
{
	int		i;
	int		ext;

	i = 1;
	ext = 0;
	if (!msh->cmd[1])
	{
		btn_export_empty(*env, 1);
		return (ext);
	}
	while (msh->cmd[i])
	{
		if (check_syntax(msh->cmd[i]) == -1)
		{
			ext = 1;
		}
		else if (check_format(msh->cmd[i]) != 0)
			valid_export(msh, env, i);
		i++;
	}
	return (ext);
}
