/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:24:25 by jchene            #+#    #+#             */
/*   Updated: 2022/03/01 13:11:28 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static int	nbr_of_words(const char *str)
{
	int	open_d_quot;
	int	open_s_quot;
	int	count;
	int	word;
	int	i;

	open_d_quot = 0;
	open_s_quot = 0;
	count = 0;
	word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && word == 0)
			word = 1;
		if (str[i] == '\'')
			open_s_quot = (open_s_quot - 1) * -1;
		else if (str[i] == '"')
			open_d_quot = (open_d_quot - 1) * -1;
		else if (str[i] == ' ' && open_d_quot == 0 && open_s_quot == 0)
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

static int	word_size(const char *str)
{
	int	size;
	int	open_d_quot;
	int	open_s_quot;

	open_d_quot = 0;
	open_s_quot = 0;
	size = 0;
	while (*str && (*str != ' ' || open_d_quot == 1 || open_s_quot == 1))
	{
		if (*str == '\'')
			open_s_quot = (open_s_quot - 1) * -1;
		if (*str == '"')
			open_d_quot = (open_d_quot - 1) * -1;
		str++;
		size++;
	}
	return (size);
}

int	ft_lst_split(t_list **list, char *str, char c)
{
	int		j;
	int		nb_words;
	int		word_len;
	char	*word;

	j = 0;
	if (!str)
		return (-1);
	if ((ft_count_occur(str, '\'') % 2 == 1)
		|| (ft_count_occur(str, '"') % 2 == 1))
		return (-1);
	nb_words = nbr_of_words(str);
	while (nb_words > 0)
	{
		while (str[j] && str[j] == c)
			j++;
		word_len = word_size(&str[j]);
		word = (char *)ft_calloc(sizeof(char), word_len + 1);
		ft_strlcpy(&word[0], &str[j], word_len + 1);
		j += word_len;
		nb_words--;
		ft_lst_add_bot(list, word);
	}
	return (0);
}
