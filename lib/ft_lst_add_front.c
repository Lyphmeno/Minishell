/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:29:38 by jchene            #+#    #+#             */
/*   Updated: 2021/11/23 16:07:00 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lst_add_front(t_elem *elem, t_start *stack)
{
	if (stack->start == NULL)
		stack->start = elem;
	else
	{
		elem->next = stack->start;
		stack->start = elem;
	}
}