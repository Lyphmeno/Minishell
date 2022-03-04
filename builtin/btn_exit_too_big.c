/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btn_exit_too_big.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 22:10:34 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:13:22 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ll_max(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_is_digit(s[i]) == 1)
	{
		i++;
		j++;
	}
	if (j > 19)
		return (1);
	return (0);
}

int	check_limits(unsigned long long n, int signe)
{
	if (signe == -1 && n > 9223372036854775808uLL)
		return (1);
	if (signe == 1 && n > 9223372036854775807uLL)
		return (1);
	return (0);
}

int	is_too_big(char *cmd)
{
	int					i;
	int					signe;
	unsigned long long	n;

	i = 0;
	signe = 1;
	n = 0;
	if (ll_max(cmd) == 1)
		return (1);
	while (cmd[i] == ' ' || (cmd[i] >= 9 && cmd[i] <= 13))
		i++;
	if (cmd[i] == '-' || cmd[i] == '+')
	{
		if (cmd[i] == '-')
			signe = -1;
		i++;
	}
	while (ft_is_digit(cmd[i]) == 1)
	{
		n = 10 * n + cmd[i] - '0';
		i++;
	}
	if (check_limits(n, signe) == 1)
		return (1);
	return (0);
}
