/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_export_empty_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:47:48 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:15:34 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	error_export(char *arg, char *msg)
{
	char	*true_msg;

	true_msg = ft_strjoins("minishell: export: `", arg, msg);
	ft_putstr_fd(true_msg, 2);
	free(true_msg);
}

int	cmp_key(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] != '=' && s2[i] != '=' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	fill_joinenv(char *joined, char *key, char *value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (key[i])
	{
		joined[j] = key[i];
		i++;
		j++;
	}
	joined[j] = '=';
	j++;
	joined[j] = '\"';
	j++;
	i = 0;
	while (value[i])
	{
		joined[j] = value[i];
		i++;
		j++;
	}
	joined[j] = '\"';
	j++;
	joined[j] = '\0';
}

char	*strjoinenv(t_env *env)
{
	char	*joined;

	joined = malloc(sizeof(char) *(ft_strlen(env->key)
				+ ft_strlen(env->value) + 4));
	if (!joined)
		return (NULL);
	fill_joinenv(joined, env->key, env->value);
	return (joined);
}

void	sort_env(char **strs)
{
	int		i;
	int		j;
	char	*tmp;
	int		size;

	i = 0;
	j = 0;
	while (strs[i])
		i++;
	size = i;
	while (j < size)
	{
		i = 0;
		while (strs[i])
		{
			if (strs[i + 1] && cmp_key(strs[i], strs[i + 1]) > 0)
			{
				tmp = strs[i];
				strs[i] = strs[i + 1];
				strs[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}
