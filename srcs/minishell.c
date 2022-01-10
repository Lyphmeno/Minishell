/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/10 13:09:41 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

/*void	sighandler(int sig)
{

}*/

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	//signal(SIGINT, sighandler);

	*(st_env()) = parse_env(envp);
	while (1)
	{
		st_mini()->line = readline("$> ");
		//parsing_base();
		free(st_mini()->line);
	}
	return (0);
}
