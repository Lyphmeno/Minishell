/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:38:20 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/26 17:00:41 by hlevi            ###   ########.fr       */
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

void	btn_exit_empty(t_env *env)
{
	int		exit_code;
	char	*val;

	exit_code = 0;
	val = get_env("?", env);
	if (val != NULL)
		exit_code = ft_atoi(val);
	// FREE MINISHELL
	ft_putstr_fd("exit", 1);
	exit(exit_code);
}

int	btn_exit(t_env *env, char *str)
{
	long long	exit_code;

	if (str == NULL) 
		btn_exit_empty(env);
	else if (argc > 1)
		// Too many argument
	else if (is_string(str) == 1)
		// not numeric return 
	else
		// EXIT
	return (0);
}
