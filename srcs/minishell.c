/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/24 16:36:29 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/*void	sighandler(int sig)
{
	if ()
}*/

int	main(int argc, char **argv, char **env)
{
	(void)env;
	(void)argc;
	(void)argv;
	//signal(SIGINT, sighandler);
	while (1)
	{
		st_mini()->line = readline("$> ");
		parsing_base();
		free(st_mini()->line);

	}
	return (0);
}
