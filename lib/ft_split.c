/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:47:24 by hlevi             #+#    #+#             */
/*   Updated: 2021/11/24 13:32:37 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	nbr_of_words(const char *str, char c)
{
	int	count;
	int	word;
	int	i;

	count = 0;
	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && word == 0)
			word = 1;
		else if (str[i] == c)
		{
			if (word)
				count++;
			word = 0;
		}
		i++;
	}
	if (word)
		count++;
	return (count);
}

static int	word_size(const char *str, char c)
{
	int	size;

	size = 0;
	while (*str != c && *str)
	{
		str++;
		size++;
	}
	return (size);
}

char	**ft_split(const char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		nb_words;
	int		word_len;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	nb_words = nbr_of_words(str, c);
	tab = (char **)ft_newarray(sizeof(char *), nb_words + 1, sizeof(char *));
	while (i < nb_words)
	{
		while (str[j] == c && str[j])
			j++;
		word_len = word_size(&str[j], c);
		tab[i] = (char *)ft_calloc(sizeof(char), word_len + 1);
		ft_strlcpy(&tab[i++][0], &str[j], word_len + 1);
		j += word_len;
	}	
	tab[i] = NULL;
	return (tab);
}

t_start	*ft_lst_split(const char *str, char c)
{
	t_start	*word;
	int		i;
	int		j;
	int		nb_words;
	int		word_len;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	nb_words = nbr_of_words(str, c);
	tab = (char **)ft_newarray(sizeof(char *), nb_words + 1, sizeof(char *));
	while (i < nb_words)
	{
		while (str[j] == c && str[j])
			j++;
		word_len = word_size(&str[j], c);
		tab[i] = (char *)ft_calloc(sizeof(char), word_len + 1);
		ft_strlcpy(&tab[i++][0], &str[j], word_len + 1);
		j += word_len;
	}	
	tab[i] = NULL;
	return (tab);
}
