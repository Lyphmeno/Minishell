/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:01:14 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 19:07:31 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_file(char **linetab, int index)
{
	if (index == 0)
		return (0);
	if (linetab[-1][0] == '<' || linetab[-1][0] == '>')
		return (1);
	return (0);
}

void	set_pipe(t_msh *msh, char **linetab, int index)
{
	int	i;

	i = 0;
	if (msh->infile == NULL && index != 0)
		add_file(&msh->infile, PIPE, NULL);
	while (linetab[i] && linetab[i][0] != '|')
		i++;
	if (msh->outfile == NULL && linetab[i])
		add_file(&msh->outfile, PIPE, NULL);
}

void	add_file(t_file **files, int type, char *name)
{
	t_file	*new;
	t_file	*index;

	new = malloc(sizeof(t_file));
	if (new == NULL)
		return ;
	new->type = type;
	new->name = ft_strdup(name);
	if (*files == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		*files = new;
	}
	else
	{
		index = *files;
		while (index->next != NULL)
			index = index->next;
		new->next = NULL;
		new->prev = index;
		index->next = new;
	}
}

void	af_msh(t_msh *msh, char **linetab)
{
	int	i;

	i = 0;
	while (linetab[i] && linetab[i][0] != '|')
	{
		if (!is_sep(linetab[i][0]) && is_file(linetab + i, i))
		{
			if (linetab[i - 1][0] == '<')
			{
				if (linetab[i - 1][1] && linetab[i - 1][1] == '<')
					add_file(&msh->infile, HEREDOC, linetab[i]);
				else
					add_file(&msh->infile, INFILE, linetab[i]);
			}
			if (linetab[i - 1][0] == '>')
			{
				if (linetab[i - 1][1] && linetab[i - 1][1] == '>')
					add_file(&msh->outfile, APPEND, linetab[i]);
				else
					add_file(&msh->outfile, REPLACE, linetab[i]);
			}
		}
		i++;
	}
}

void	bf_msh(t_msh *msh, char **linetab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (!is_sep(linetab[i][0]) && is_file(linetab + i, i))
		{
			if (linetab[i - 1][0] == '<')
			{
				if (linetab[i - 1][1] && linetab[i - 1][1] == '<')
					add_file(&msh->infile, HEREDOC, linetab[i]);
				else
					add_file(&msh->infile, INFILE, linetab[i]);
			}
			if (linetab[i - 1][0] == '>')
			{
				if (linetab[i - 1][1] && linetab[i - 1][1] == '>')
					add_file(&msh->outfile, APPEND, linetab[i]);
				else
					add_file(&msh->outfile, REPLACE, linetab[i]);
			}
		}
		i++;
	}
}
