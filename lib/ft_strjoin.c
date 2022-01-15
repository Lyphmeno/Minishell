/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:57:18 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/15 15:59:23 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!(s1 && s2))
		return (NULL);
	str = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}
