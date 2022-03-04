/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:23:00 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:26:34 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	handler_quit(int sig)
{
	if (sig == SIGQUIT && g_exit >= 0)
		write(1, "\b\b  \b\b", 6);
	else if (sig == SIGQUIT && g_exit < 0)
		return ;
}

void	handler_int(int sig)
{
	if (sig == SIGINT && g_exit >= 0)
	{
		rl_replace_line("", 1);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		g_exit = 130;
	}
	else if (sig == SIGINT && g_exit < 0)
	{
		rl_replace_line("", 1);
		write(1, "\n", 1);
		rl_on_new_line();
		g_exit = 130;
	}
}

void	handler_child(int sig)
{
	if (sig == SIGQUIT)
		exit(131);
	else if (sig == SIGINT)
		exit(130);
}

void	handler_heredoc(int sig)
{
	if (sig == SIGQUIT)
		write(1, "\b\b  \b\b", 6);
	if (sig == SIGINT)
		exit(130);
}

void	sighandler(int mode)
{
	if (mode == 1)
	{
		signal(SIGINT, handler_int);
		signal(SIGQUIT, handler_quit);
	}
	if (mode == 2)
	{
		signal(SIGINT, handler_child);
		signal(SIGQUIT, handler_child);
	}
	if (mode == 3)
	{
		signal(SIGINT, handler_heredoc);
		signal(SIGQUIT, handler_heredoc);
	}
}

