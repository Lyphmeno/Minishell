/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_join_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:59:05 by jchene            #+#    #+#             */
/*   Updated: 2021/11/27 20:01:18 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	ft_lst_join_size(t_elem *start, t_elem *stop)
{
	int		len;
	t_elem	*tmp;

	len = 0;
	tmp = start;
	if (!tmp)
		return (0);
	while (tmp != stop)
	{
		len += ft_strlen(tmp->word);
		tmp = tmp->next;
	}
	len += ft_strlen(tmp->word);
	return (len);
}
