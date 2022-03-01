/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:20:09 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 13:48:06 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	error_export(char *arg, char *msg)
{
	char	*true_msg;

	true_msg = ft_strjoins("minishell: export: ", arg, msg);
	ft_putstr_fd(true_msg, 2);
	free(true_msg);
}

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

	key = get_key(msh->arg[i]);
	value = get_value(msh->arg[i]);
	if (get_env_index(key, *env) == -1)
		add_env(key, value, env);
	else
		set_env(key, value, *env);
	free(key);
	free(value);
}

int	btn_export(t_msh *msh, t_env **env)
{
	int		i;

	i = 0;
	if (msh->argnb == 0)
	{
		env_export(*env);
		return (g_exit);
	}
	while (msh->arg[i])
	{
		if (check_syntax(msh->arg[i]) == -1)
		{
			g_exit = -1;
		}
		else if (check_format(msh->arg[i]) != 0)
			valid_export(msh, env, i);
		i++;
	}
	return (g_exit);
}
