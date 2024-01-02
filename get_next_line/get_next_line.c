/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuneer <smuneer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:52:19 by smuneer           #+#    #+#             */
/*   Updated: 2023/11/21 15:00:00 by smuneer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_one_line(int fd, char *st_line)
{
	int		read_count;
	char	*line;
	char	*ln_ptr;

	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	read_count = 1;
	while (read_count > 0 && !ft_strchr(st_line, '\n'))
	{
		ln_ptr = st_line;
		read_count = read (fd, line, BUFFER_SIZE);
		if (read_count < 0)
		{
			free(line);
			free(st_line);
			return (NULL);
		}
		line[read_count] = '\0';
		st_line = ft_strjoin(st_line, line);
		free (ln_ptr);
	}
	free(line);
	return (st_line);
}

int	check_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

char	*ft_line_static(char *full_str)
{
	char	*l;
	int		i;

	i = 0;
	if (!full_str[i])
		return (NULL);
	while (full_str[i] != '\0' && full_str[i] != '\n')
		i++;
	i += check_newline(full_str[i]);
	l = (char *) malloc (sizeof(char) * (i + 1));
	if (!l)
		return (NULL);
	i = 0;
	while (full_str[i] && full_str[i] != '\n')
	{
		l[i] = full_str[i];
		i++;
	}
	if (full_str[i] == '\n')
	{
		l[i] = full_str[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

char	*ft_rest_str(char *full_str)
{
	char	*l;
	int		i;
	int		j;

	i = 0;
	while (full_str[i] && full_str[i] != '\n')
		i++;
	if (full_str[i] == '\n')
		i += 1;
	if (full_str[i] == '\0' || !full_str)
	{
		free(full_str);
		return (NULL);
	}
	l = (char *) malloc (sizeof(char) * (ft_strlen(full_str) - i + 1));
	if (!l)
		return (NULL);
	j = 0;
	while (full_str[i])
	{
		l[j++] = full_str[i++];
	}
	l[j] = '\0';
	free(full_str);
	return (l);
}

char	*get_next_line(int fd)
{
	char		*tmp_line;
	static char	*st_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	st_line = get_one_line(fd, st_line);
	if (!st_line)
		return (NULL);
	tmp_line = ft_line_static(st_line);
	st_line = ft_rest_str(st_line);
	return (tmp_line);
}
