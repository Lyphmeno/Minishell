/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_export_empty.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:45:23 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:16:12 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	env_size(t_env *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		i++;
		env = env->next;
	}
	return (i);
}

char	**env_to_chartwo(t_env *env)
{
	int		i;
	char	**ret;

	if (env == NULL)
		return (NULL);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (env_size(env) + 1));
	while (env != NULL)
	{
		ret[i] = strjoinenv(env);
		i++;
		env = env->next;
	}
	ret[i] = NULL;
	return (ret);
}

void	btn_export_empty(t_env *env, int output)
{
	char	**linetab;
	int		i;

	linetab = env_to_chartwo(env);
	sort_env(linetab);
	i = 1;
	while (linetab[i])
	{
		write(output, "declare -x ", 11);
		ft_putendl_fd(linetab[i], output);
		i++;
	}
	free_twochar(linetab);
}
