/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2021/11/17 15:17:38 by jchene           ###   ########.fr       */
=======
/*   Updated: 2021/11/17 15:18:41 by jchene           ###   ########.fr       */
>>>>>>> hugo
=======
/*   Updated: 2021/11/17 15:19:12 by jchene           ###   ########.fr       */
>>>>>>> julien
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
		mini.line = readline("minishell:PATH$\t");
		printf("%s\n", mini.line);
		free(mini.line);	
	}
	return (0);
}
