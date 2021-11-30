/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/30 15:15:33 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/*void	sighandler(int sig)
{

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
		//parsing_base();
		free(st_mini()->line);
	}
	return (0);
}
