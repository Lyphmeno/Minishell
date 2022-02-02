/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:00:39 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/19 13:44:06 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*get_key(char *envp)
{
	int		i;
	char	*key;

	i = 0;
	while (envp[i] != '=')
		i++;
	key = ft_calloc(sizeof(char), (i + 1));
	i = 0;
	while (envp[i] != '=')
	{
		key[i] = envp[i];
		i++;
	}
	return (key);
}

char	*get_value(char *envp)
{
	char	*value;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (envp[i] != '=')
		i++;
	i++;
	value = ft_calloc(sizeof(char), (ft_strlen(envp) + 1));
	while (envp[i + j])
	{
			value[j] = envp[i + j];
			j++;
	}
	return (value);
}

void	add_env(char *envkey, char *envalue, t_env **env)
{
	t_env	*new;
	t_env	*count;

	new = (t_env *)ft_calloc(sizeof(t_env), 1);
	new->key = envkey;
	new->value = envalue;
	if (*env == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*env = new;
	}
	else
	{
		count = *env;
		while (count->next != NULL)
			count = count->next;
		new->next = NULL;
		new->prev = count;
		count->next = new;
	}
}

t_env	*parse_env(char **envp)
{
	t_env	*env;
	char	*newkey;
	char	*newvalue;
	int		i;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		newkey = get_key(envp[i]);
		newvalue = get_value(envp[i]);
		add_env(newkey, newvalue, &env);
		if (env == NULL)
			return (NULL);
		i++;
	}
	return (env);
}
