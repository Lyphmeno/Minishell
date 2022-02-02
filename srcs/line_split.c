/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchene <jchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:24:25 by jchene            #+#    #+#             */
/*   Updated: 2022/02/02 13:09:16 by jchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

static struct	s_now
{
	int	open_d;
	int	open_s;
	int	count;
	int	word;
	int	i;
}				s_now;

static int	nbr_of_words(const char *str)
{
	ft_memset(&s_now, 0, sizeof(s_now));
	while (str[s_now.i])
	{
		if (str[s_now.i] != ' ' && s_now.word == 0)
			s_now.word = 1;
		if (str[s_now.i] == '\'' && s_now.open_d == 0)
			s_now.open_s = (s_now.open_s - 1) * -1;
		else if (str[s_now.i] == '"' && s_now.open_s == 0)
			s_now.open_d = (s_now.open_d - 1) * -1;
		else if (str[s_now.i] == ' ' && s_now.open_d == 0 && s_now.open_s == 0)
		{
			if (s_now.word)
				s_now.count++;
			s_now.word = 0;
		}
		s_now.i++;
	}
	if (s_now.word)
		s_now.count++;
	return (s_now.count);
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
		if (*str == '\'' && open_d_quot == 0)
			open_s_quot = (open_s_quot - 1) * -1;
		if (*str == '"' && open_s_quot == 0)
			open_d_quot = (open_d_quot - 1) * -1;
		str++;
		size++;
	}
	return (size);
}

int	line_split(char *str, char c)
{
	int		j;
	int		nb_words;
	int		word_len;
	char	*word;

	j = 0;
	if (!str)
		return (-1);
	//printf("--dq%d\n", ft_count_quotes(str, '"'));
	//printf("--sq%d\n", ft_count_quotes(str, '\''));
	if ((ft_count_quotes(str, '\'') % 2 == 1)
		|| (ft_count_quotes(str, '"') % 2 == 1))
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
		ft_lst_add_bot(ft_lst_new_elem(word), st_words());
	}
	return (0);
}
