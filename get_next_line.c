/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/04/17 11:36:25 by pvital-m         ###   ########.fr       */
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
	int buffer_read;
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	
	buffer_read = 1;
	while(buffer_read > 0 && !ft_strchr(text, '\n'))
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if(buffer_read == -1)
		{
			free(buffer);
			return NULL;
		}
		text = ft_strjoin(text, buffer);
	}
	free(buffer);

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
	printf("%s\n", text);
	text = static_string_content(fd, text);
	printf("%s", text);
	if (!text)
		return (NULL);
	line = ft_get_line(text);
	text = ft_managestatic(text);
	return (line);
}
