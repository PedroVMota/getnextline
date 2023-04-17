/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:53:40 by pvital-m          #+#    #+#             */
/*   Updated: 2023/04/17 10:25:17 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	fd_checker(int fd)
{
	char	*a;

	a = NULL;
	if (read(fd, a, 0) < 0)
		return (1);
	return (0);
}

static char	*static_string_content(int fd, char *text)
{
	int		readn;
	char	*buf;

	readn = 1;
	int i = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (readn > 0 && !ft_strchr(text, '\n'))
	{
		readn = read(fd, buf, BUFFER_SIZE);
		if (readn == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[readn] = 0;
		i++;
		text = ft_strjoin(text, buf);
	}
	printf("%i, %s, %i\n", readn, ft_strchr(text, '\n'), i);
	free(buf);
	printf("%s", text);
	return (text);
}

static char	*ft_get_line(char *back)
{
	char	*element;
	int		index;

	index = -1;
	element = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!element)
		return (NULL);
	while (++index <= BUFFER_SIZE)
		element[index] = back[index];
	element[index] = 0;
	return (element);
}

char	*ft_managestatic(char *old)
{
	char	*new;
	int		i;
	int newi;

	newi = 0;
	i = -1;
	new = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new)
		return (NULL);
	while(old[++i])
		if(old[i] == '\n')
			break;
	while(old[++i])
	{
		*new = old[i];
		new++;
	}
	printf("\n");
	*new = 0;
	free(old);
	return (new);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*text;

	if (fd_checker(fd))
		return (NULL);
	text = static_string_content(fd, text);
	if (!text)
		return (NULL);
	line = ft_get_line(text);
	text = ft_managestatic(text);
	return (line);
}
