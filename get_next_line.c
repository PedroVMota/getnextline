/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:53:40 by pvital-m          #+#    #+#             */
/*   Updated: 2023/04/14 14:20:05 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_text(int fd, char *backup)
{
	char	*content;
	
	content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!content)
		return (NULL);
	content[BUFFER_SIZE + 1] = 0;
	read(fd, content, BUFFER_SIZE);
	ft_strjoin(backup, content);
	return content;
}

char	*get_next_line(int fd)
{
	static char	all_buffer[BUFFER_SIZE + 1];
	char *string;

	if(fd < 0)
		return (NULL);
	string = get_text(fd, all_buffer);
	printf("%s", all_buffer);
	return string;
}