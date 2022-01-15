/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_cd_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:55:23 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/15 17:04:12 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	path_size(char *path)
{
	int	i;

	i = ft_strlen(path);
	while (i >= 0)
	{
		if (path[i] == '/')
			return (i);
		i--;
	}
	return (ft_strlen(path));
}

char	*get_backpath(char *old_path)
{
	int		i;
	char	*new_path;

	i = path_size(old_path);
	new_path = (char *)ft_calloc(sizeof(char), (i + 1));
	i--;
	while (i >= 0)
	{
		new_path[i] = old_path[i];
		i--;
	}
	return (new_path);
}

int	btn_cd_back(t_env *env)
{
	int		ext_code;
	char	old_path[MAX_PATH];
	char	*new_path;

	getcwd(old_path, MAX_PATH);
	new_path = get_backpath(old_path);
	ext_code = btn_cd(&env, new_path);
	free(new_path);
	return (ext_code);
}
