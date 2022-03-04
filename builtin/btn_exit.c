/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:38:20 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/04 01:10:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_string(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_is_digit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	btn_exit_str(t_env *env, t_msh *msh)
{
	ft_putendl_fd("exit", 1);
	ft_putstr_fd("minishell: exit: ", 2);
	ft_putstr_fd(msh->cmd[1], 2);
	ft_putendl_fd(" : numeric argument requiered", 2);
	free_all(env, msh);
	exit(2);
}

void	btn_exit_empty(t_env *env, t_msh *msh)
{
	int		ext;
	char	*val;

	ext = 0;
	val = ft_strdup(get_env("?", env));
	ext = ft_atoi(val);
	free(val);
	free_all(env, msh);
	ft_putendl_fd("exit", 1);
	exit(ext);
}

int	btn_exit(t_env *env, t_msh *msh)
{
	long long	ext;

	if (msh->cmd[1] == NULL)
		btn_exit_empty(env, msh);
	else if (is_string(msh->cmd[1]) == 1)
		btn_exit_str(env, msh);
	else if (is_string(msh->cmd[1]) == 0 && msh->cmd[2] != NULL)
	{
		ft_putendl_fd("exit", 1);
		ft_putendl_fd("minishell: exit: too many arguments", 1);
		return (1);
	}
	else if (is_too_big(msh->cmd[1]) == 1)
		btn_exit_str(env, msh);
	else
	{
		ext = ft_atoi(msh->cmd[1]);
		free_all(env, msh);
		ft_putendl_fd("exit", 1);
		exit(ext % 256);
	}
	return (0);
}
