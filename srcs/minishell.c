/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/11/18 17:06:55 by hlevi            ###   ########.fr       */
=======
/*   Updated: 2021/11/17 15:45:18 by jchene           ###   ########.fr       */
>>>>>>> c7c5b20725f36838f4766931d0dda4f3d21e1c19
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
