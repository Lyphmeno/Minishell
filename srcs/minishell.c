/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/10 15:44:29 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	print_env(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
		{
			printf("%s=%s\n", tmp->key, tmp->value);
			tmp = tmp->next;
			i++;
		}
		printf("%s=%s\n", tmp->key, tmp->value);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*test;

	(void)argc;
	(void)argv;
	env = NULL;
	env = parse_env(envp);
	print_env(env);
	test = ft_strdup(get_env("SHELL", env));
	printf("test = %s\n", test);
	while (1)
	{
		st_mini()->line = readline("$> ");
		//parsing_base();
		free(st_mini()->line);
	}
	return (0);
}
