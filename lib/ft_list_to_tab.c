/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:18:40 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 13:34:08 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_size(t_env *env)
{
	int	i;

	i = 0;
	while (env != NULL)
	{
		env = env->next;
		i++;
	}
	return (i);
}

char	**ft_envtotab(t_env *env)
{
	int		i;
	char	**tab;

	i = 0;
	if (env == NULL)
		return (NULL);
	tab = (char **)ft_newarray(sizeof(char *),
			get_size(env) + 1, sizeof(char *));
	while (env)
	{
		tab[i] = ft_strjoins(env->key, "=", env->value);
		env = env->next;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	ft_cmdtotab(t_msh *msh, t_list *list)
{
	int		i;
	t_list	*tmplist;

	i = 0;
	if (list == NULL)
		return ;
	tmplist = list->next;
	msh->cmd = ft_strdup(tmplist->word);
	tmplist = tmplist->next;
	msh->arg = (char **)ft_newarray(sizeof(char *),
			ft_lstlen(list) + 1, sizeof(char *));
	while (tmplist != NULL)
	{
		msh->arg[i] = ft_calloc(sizeof(char), ft_strlen(tmplist->word) + 1);
		ft_strlcpy(&msh->arg[i][0], tmplist->word,
			ft_strlen(tmplist->word) + 1);
		tmplist = tmplist->next;
		i++;
	}
	msh->arg[i] = NULL;
	msh->argnb = i;
	free_lst(list);
}
