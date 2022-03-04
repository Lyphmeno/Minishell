/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_msh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:31:22 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 19:14:24 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	last_rm(t_msh *msh)
{
	t_msh	*tmpmsh;
	int		i;
	char	**cmds;

	tmpmsh = msh;
	while (msh != NULL)
	{
		i = 0;
		while (msh->cmd[i])
		{
			cmds = msh->cmd;
			if ((cmds[i][0] == '\"' || cmds[i][0] == '\'')
				&& cmds[i][1] && is_sep(cmds[i][1]))
				cmds[i] = remove_quote(cmds[i], 0);
			i++;
		}
		msh = msh->next;
	}
	msh = tmpmsh;
}

int	init_files(t_msh *msh, char **linetab, int index)
{
	int		i;
	int		j;
	t_file	*infile;
	t_file	*outfile;

	infile = NULL;
	outfile = NULL;
	i = 0;
	j = 0;
	while (msh->next != NULL)
		msh = msh->next;
	msh->infile = infile;
	msh->outfile = outfile;
	while (index > 0 && linetab[j][0] != '|')
	{
		j--;
		index--;
	}
	bf_msh(msh, &linetab[j], -j);
	af_msh(msh, &linetab[i]);
	set_pipe(msh, linetab, index);
	while (linetab[i] && !is_sep(linetab[i][0]))
		i++;
	return (i);
}

void	init_msh(t_msh **msh, char **linetab)
{
	t_msh	*tmpmsh;
	int		argnb;

	tmpmsh = ft_calloc(sizeof(t_msh), 1);
	argnb = get_argnb(linetab);
	tmpmsh->cmd = ft_calloc(sizeof(char *), (argnb + 1));
	fill_cmd(linetab, tmpmsh->cmd);
	tmpmsh->cmd[argnb] = NULL;
	tmpmsh->rerror = get_rerror(linetab);
	tmpmsh->input = 0;
	tmpmsh->output = 1;
	tmpmsh->pipein = 0;
	tmpmsh->pipeout = 1;
	add_cmd(msh, tmpmsh);
}

t_msh	*handle_msh(char **linetab)
{
	t_msh	*msh;
	int		i;

	i = 0;
	msh = NULL;
	if (linetab[0] == NULL)
		return (NULL);
	while (linetab[i])
	{
		init_msh(&msh, &linetab[i]);
		init_files(msh, &linetab[i], i);
		while (linetab[i] && linetab[i][0] != '|')
			i++;
		if (linetab[i])
			i++;
	}
	last_rm(msh);
	return (msh);
}
