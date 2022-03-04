/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 15:10:31 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/04 01:04:40 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	get_word_len(char *line)
{
	int	i;

	i = 0;
	if (is_sep(line[i]))
		return (check_sep(line));
	if (line[i] == '\'' || line[i] == '\"')
		return (check_quotes(line));
	while (line[i] && line[i] != ' ' && !is_sep(line[i]))
	{
		if ((line[i] == '\'' || line[i] == '\'') && closed_quotes(&line[i]))
			i += check_quotes(&line[i]);
		if (line[i] && line[i] != ' ' && !is_sep(line[i]))
			i++;
	}
	return (i);
}

char	*word_cpy(char *line)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	len = get_word_len(line);
	word = ft_calloc(sizeof(char), (len + 1));
	while (i < len)
	{
		word[i] = line[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	get_nbr_words(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		count += next_word(&line[i]);
		i += check_word(&line[i]);
	}
	return (count);
}

void	fill_tab(char **linetab, char *line, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		linetab[i] = word_cpy(&line[j]);
		j += check_word(&line[j]);
		while (line[j] == ' ')
			j++;
		i++;
	}
	linetab[i] = NULL;
}

char	**splitline(char *line)
{
	char	**linetab;
	int		len;

	if (!line)
	{
		linetab = ft_calloc(sizeof(char *), 1);
		linetab[0] = NULL;
		return (linetab);
	}
	while (*line && *line == ' ')
		line++;
	len = get_nbr_words(line);
	linetab = ft_calloc(sizeof(char *), (len + 1));
	fill_tab(linetab, line, len);
	return (linetab);
}
