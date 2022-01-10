/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:00:39 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/10 15:21:20 by hlevi            ###   ########.fr       */
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
	key = malloc(sizeof(char) * (i + 1));
	if (!key)
		return (NULL);
	i = 0;
	while (envp[i] != '=')
	{
		key[i] = envp[i];
		i++;
	}
	key[i] = '\0';
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
	value = malloc(sizeof(char) * (ft_strlen(envp) + 1));
	if (!value)
		return (NULL);
	while (envp[i + j])
	{
			value[j] = envp[i + j];
			j++;
	}
	value[j] = '\0';
	return (value);
}

void	add_env(char *name, char *value, t_env **env)
{
	t_env	*new;
	t_env	*count;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		return ;
	new->key = ft_strdup(name);
	new->value = ft_strdup(value);
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
	int		i;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		add_env(get_key(envp[i]), get_value(envp[i]), &env);
		if (env == NULL)
			return (NULL);
		i++;
	}
	return (env);
}
