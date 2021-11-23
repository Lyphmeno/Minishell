/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/23 15:18:58 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_msh	mini;

	(void)env;
	(void)argc;
	(void)argv;
	while (1)
	{
		mini.line = readline("$> ");
		parsing_base(&mini);
		free(mini.line);
	}
	return (0);
}
