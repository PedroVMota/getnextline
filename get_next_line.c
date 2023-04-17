/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/04/17 12:10:25 by pvital-m         ###   ########.fr       */
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
	int		i;

	i = -1;
	element = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!element)
		return (NULL);
	while(back[++i])
	{
		if(back[i] == '\n')
		{
			element[i] = back[i];
			break;
		}
		element[i] = back[i];
	}
	return (element);
}

char	*ft_managestatic(char *old)
{
	char		*new;
	int		i;
	int ni;

	ni = 0;
	i = -1;
	new = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!new)
		return (NULL);
	while(old[++i])
		if(old[i] == '\n')
			break;
	while(old[++i])
	{
		new[ni] = old[i];
		ni++;
	}
	new[ni] = 0;
	
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
