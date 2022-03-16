/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:32:28 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 22:24:35 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_env	*first(t_env *env)
{
	while (env->prev != NULL)
		env = env->prev;
	return (env);
}

int	check_syntax_unset(char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		if (!((src[i] >= 'a' && src[i] <= 'z') || (src[i] >= 'A'
					&& src[i] <= 'Z') || (src[i] == '_')))
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

void	remove_node(t_env **env)
{
	t_env	*tmp1;
	t_env	*tmp2;

	tmp1 = (*env)->prev;
	tmp2 = (*env)->next;
	if (tmp1 != NULL)
		tmp1->next = tmp2;
	if (tmp2 != NULL)
		tmp2->prev = tmp1;
	free((*env)->key);
	free((*env)->value);
	free(*env);
	if (tmp1 == NULL && tmp2 == NULL)
		*env = NULL;
	if (tmp1 != NULL)
		*env = first(tmp1);
	if (tmp2 != NULL)
		*env = first(tmp2);
}

int	valid_unset(char *key)
{
	int		ext;

	ext = 0;
	if (check_syntax_unset(key) == -1)
	{
		ft_putstr_fd("minishell: unset: `", 2);
		ft_putstr_fd(key, 2);
		ft_putendl_fd("': not a valid indentifier", 2);
		ext = 1;
	}
	return (ext);
}

int	btn_unset(char **keys, t_env **env)
{
	int		i;
	int		j;
	int		index;
	int		ext;

	j = 0;
	ext = 0;
	while (keys[++j] != NULL)
	{
		ext = valid_unset(keys[j]);
		index = get_env_index(keys[j], *env);
		if (index < 0 || *env == NULL)
			ext = 1;
		i = 0;
		while (i < index && *env != NULL)
		{
			*env = (*env)->next;
			i++;
		}
		if (*env == NULL)
			ext = 1;
		remove_node(env);
		*env = first(*env);
	}
	return (ext);
}
