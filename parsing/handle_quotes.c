/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 18:06:43 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 18:16:33 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

void	quotes_add(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

void	noquotes_fill(char *tmp, char *line, int index, char c)
{
	int	i;
	int	j;

	i = -1;
	while (++i < index)
		tmp[i] = line[i];
	j = i;
	while (line[i] != c)
	{
		tmp[j] = line[i];
		quotes_add(&i, &j);
	}
	i++;
	while (line[i] != c)
	{
		tmp[j] = line[i];
		quotes_add(&i, &j);
	}
	i++;
	while (line[i])
	{
		tmp[j] = line[i];
		quotes_add(&i, &j);
	}
	tmp[j] = '\0';
}

int	noquotes_size(char *line, int index, int c)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < index)
		quotes_add(&i, &len);
	while (line[i] != c)
		quotes_add(&i, &len);
	i++;
	while (line[i] != c)
		quotes_add(&i, &len);
	i++;
	while (line[i])
		quotes_add(&i, &len);
	return (len);
}

char	*remove_quote(char *line, int index)
{
	int		i;
	int		len;
	char	c;
	char	*tmp;

	i = index;
	if (!line[i])
		return (line);
	while (line[i] && line[i] != '\'' && line[i] != '\"')
		i++;
	if (!line[i])
		return (line);
	if (!closed_quotes(&line[i]))
		return (line);
	c = line[i];
	while (line[i + 1] && line[i + 1] != c)
		i++;
	len = noquotes_size(line, index, c);
	tmp = ft_calloc(sizeof(char), (len + 1));
	if (!tmp)
		return (NULL);
	noquotes_fill(tmp, line, index, c);
	free(line);
	return (remove_quote(tmp, i));
}

void	handle_quotes(char **linetab)
{
	int	i;

	i = 0;
	while (linetab[i])
	{
		if (contain_no_quotes(linetab[i]))
			linetab[i] = nosp(linetab[i]);
		else if (linetab[i][0] && !is_sep(linetab[i][1]))
			linetab[i] = remove_quote(linetab[i], 0);
		i++;
	}
}
