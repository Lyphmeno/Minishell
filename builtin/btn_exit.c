/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:38:20 by hlevi             #+#    #+#             */
/*   Updated: 2022/02/23 15:49:46 by hlevi            ###   ########.fr       */
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
	ft_putstr_fd(msh->arg[0], 2);
	ft_putendl_fd(" : numeric argument requiered", 2);
	free_all(env, msh);
	exit(2);
}

void	btn_exit_empty(t_env *env, t_msh *msh)
{
	int		exit_code;
	char	*val;

	exit_code = 0;
	val = get_env("?", env);
	if (val != NULL)
		exit_code = ft_atoi(val);
	free_all(env, msh);
	ft_putendl_fd("exit", 1);
	exit(exit_code);
}

int	btn_exit(t_env *env, t_msh *msh)
{
	long long	exit_code;

	if (!msh->arg[0])
		btn_exit_empty(env, msh);
	else if (msh->argnb > 1)
	{
		ft_putendl_fd("exit", 1);
		ft_putendl_fd("minishell: exit: too many arguments", 1);
		return (1);
	}
	else if (is_string(msh->arg[0]) == 1)
		btn_exit_str(env, msh);
	else
	{
		exit_code = ft_atoi(msh->arg[0]);
		free_all(env, msh);
		ft_putendl_fd("exit", 1);
		exit(exit_code % 256);
	}
	return (0);
}
