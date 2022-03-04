/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlevi <hlevi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:31:01 by hlevi             #+#    #+#             */
/*   Updated: 2022/03/03 23:50:44 by hlevi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

char	*get_namedoc(void)
{
	int		nb;
	int		loop;
	char	*name;
	char	*num;

	loop = 1;
	nb = 0;
	while (loop == 1)
	{
		num = ft_itoa(nb);
		name = ft_strjoin("heredoc_", num);
		free(num);
		if (access(name, F_OK) != 0)
			loop = 0;
		else
		{
			nb++;
			free(name);
		}
	}
	return (name);
}

char	*dup_doc(char *s)
{
	int		len;
	char	*cpy;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) + 2;
	cpy = ft_calloc(sizeof(char), len);
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s, ft_strlen(s) + 1);
	cpy[len - 2] = '\n';
	return (cpy);
}

char	*join_doc(char *s1, char *s2)
{
	int		size;
	char	*new;

	if (s1 == NULL)
		return (dup_doc(s2));
	size = ft_strlen(s1) + ft_strlen(s2) + 2;
	new = ft_calloc(sizeof(char), size);
	if (new == NULL)
		return (s1);
	ft_strlcpy(new, s1, ft_strlen(s1) + 1);
	ft_strlcat(new, s2, ft_strlen(new) + ft_strlen(s2) + 1);
	new[size - 2] = '\n';
	return (new);
}

void	send_heredoc(char *heredoc, t_file *infile)
{
	int		fd;
	char	*name;

	name = get_namedoc();
	fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IWUSR
			| S_IRGRP | S_IROTH);
	write(fd, heredoc, ft_strlen(heredoc));
	close(fd);
	free(heredoc);
	free(infile->name);
	infile->name = ft_strdup(name);
	free(name);
}

char	*get_heredoc(int fd)
{
	int		bytes;
	char	buffer[4097];
	char	*heredoc;
	char	*tmp;

	heredoc = NULL;
	bytes = read(fd, buffer, 4096);
	while (bytes)
	{
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		tmp = ft_strjoin(buffer, heredoc);
		free(heredoc);
		heredoc = tmp;
		bytes = read(fd, buffer, 4096);
	}
	return (heredoc);
}
