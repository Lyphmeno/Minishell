/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:00:39 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/10 13:10:46 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	add_env(char *name, char *value, t_env **env )
{

}

t_env	parse_env(char **envp)
{
	t_env	env;
	int		i;

	i = 0;
	env = 0;
	while (envp[i])
	{

	}
	return (env);
}