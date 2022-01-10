/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/10 15:01:10 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_env(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	printf("--------------------VARIABLE ENV--------------------\n");
	tmp = env;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			printf("[%s]:----> %s\n", tmp->key, tmp->value);
			tmp = tmp->next;
			i++;
		}
		printf("v[%s]:----> NULL\n", tmp->key);
	}
	printf("----------------------------------------\n\n");
}

/*void	sighandler(int sig)
{

}*/

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_env	*env;
	//signal(SIGINT, sighandler);

	env = NULL;
	env = parse_env(envp);
	print_env(env);
	// while (1)
	// {
	// 	st_mini()->line = readline("$> ");
	// 	//parsing_base();
	// 	free(st_mini()->line);
	// }
	return (0);
}
