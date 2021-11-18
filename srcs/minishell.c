/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/18 19:07:36 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	err_handler(int err_code)
{
	if (err_code == RL_EOF)
		printf("bad_path\n");
	return (-1);
}

int	main(int argc, char **argv, char **env)
{
	t_msh	mini;

	(void)env;
	(void)argc;
	(void)argv;
	while (1)
	{
		mini.line = readline("$> ");
		if (!mini.line)
			break ;
		printf("%s\n", mini.line);
		free(mini.line);
	}
	return (0);
}
