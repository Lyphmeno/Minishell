/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinmore.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:09:18 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/01 13:43:02 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*ft_strjoins(char *str1, char *str2, char *str3)
{
	char	*str;

	str = ft_calloc(sizeof(char), (ft_strlen(str1) + ft_strlen(str2)
				+ ft_strlen(str3) + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, str1, ft_strlen(str1) + 1);
	ft_strlcat(str, str2, ft_strlen(str) + ft_strlen(str2) + 1);
	ft_strlcat(str, str3, ft_strlen(str) + ft_strlen(str3) + 1);
	return (str);
}
