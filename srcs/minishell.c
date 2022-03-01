/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:53:27 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 18:51:56 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	shlvl(t_env *env)
{
	int		lvl;
	char	*tmp;

	if (get_env_index("SHLVL", env) == -1)
		add_env("SHLVL", "1", &env);
	lvl = ft_atoi(get_env("SHLVL", env));
	lvl++;
	tmp = ft_itoa(lvl);
	set_env("SHLVL", tmp, env);
	free(tmp);
}

void	exe_base(t_env **env, t_msh *msh)
{
	t_msh	*tmp;

	tmp = msh;
	exe_all(env, msh);
	if (g_exit == 131)
	{
		write(1, "Quit (core dumped)", 18);
		rl_replace_line("", 1);
		write(1, "\n", 1);
		rl_on_new_line();
	}
	free_msh(tmp);
}

void	true_readline(t_env	**env)
{
	t_msh	*msh;
	t_list	*list;
	char	*line;

	line = readline("minishell$> ");
	while (line)
	{
		msh = ft_calloc(sizeof(t_msh), 1);
		list = ft_calloc(sizeof(t_list), 1);
		add_history(line);
		if (line[0])
		{
			// parsing_base(line, &list);
			// ft_cmdtotab(msh, list);
			msh = parse_all(line, env);
			if (msh)
				exe_base(env, msh);
			wait(NULL);
		}
		else
			free(line);
		line = readline("minishell$> ");
	}
	rl_clear_history();
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("ERROR: Too many arguments", 2);
		return (1);
	}
	env = NULL;
	g_exit = 0;
	env = parse_env(envp);
	add_env("?", "0", &env);
	shlvl(env);
	true_readline(&env);
	free_env(env);
	write(1, "exit\n", 5);
	exit (g_exit);
}
