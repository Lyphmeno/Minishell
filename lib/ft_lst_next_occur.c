/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_next_occur.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:15:26 by jchene            #+#    #+#             */
/*   Updated: 2021/11/25 23:33:40 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

t_elem	*ft_lst_next_occur(t_elem *elem, char c)
{
	t_elem	*tmp;

	tmp = elem;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		if (ft_charset(tmp->word, c))
			return (tmp);
		tmp = tmp->next;
	}
	if (ft_charset(tmp->word, c))
		return (tmp);
	return (NULL);
}
