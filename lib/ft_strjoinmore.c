/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinmore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:09:18 by hlevi             #+#    #+#             */
/*   Updated: 2022/01/26 14:17:37 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*ft_strjoinmore(char *str1, char *str2, char *str3)
{
	char	*str;

	str = ft_calloc(sizeof(char), (ft_strlen(str1) + ft_strlen(str2)
				+ ft_strlen(str3)));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, str1, ft_strlen(str1) + 1);
	ft_strlcpy(str, str2, ft_strlen(str) + ft_strlen(str2) + 1);
	ft_strlcpy(str, str3, ft_strlen(str) + ft_strlen(str3) + 1);
	return (str);
}
