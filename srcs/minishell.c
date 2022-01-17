/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/17 13:18:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void)argc;
	(void)argv;
	env = NULL;
	env = parse_env(envp);
	btn_env(env);
	btn_export("SHLL=2", &env);
	btn_export("SHELL=2", &env);
	btn_env(env);
	// while (1)
	// {
	// 	st_mini()->line = readline("$> ");
	// 	//parsing_base();
	// 	free(st_mini()->line);
	// }
	return (0);
}
