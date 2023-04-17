/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:37:40 by pvital-m          #+#    #+#             */
/*   Updated: 2023/04/17 18:08:47 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *buff)
{
	int		i;
	int		j;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(s1) + ft_strlen(buff)] = '\0';
	return (str);
}

char	*ft_backup(char *line, char *old)
{
	int i1;
	int i2;
	int len2;
	int len1;
	char *new_line;

	len1 = ft_strlen(line);
	len2 = ft_strlen(old);
	new_line = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_line)
		return (NULL);
	while (line && line[i1])
	{
		new_line[i1] = line[i1];
		i1++;
	}
	while (old && i2 < len2)
		new_line[i1++] = old[i2++];
	new_line[i1] = 0;
	if (line)
		free(line);
	return (new_line);
}

