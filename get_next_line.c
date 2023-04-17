/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:03:46 by pvital-m          #+#    #+#             */
/*   Updated: 2023/04/17 17:54:19 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
	all is the static memory;
	ret is gonna be the current line of the file,	
*/
char	*get_next_line(int fd)
{
	static char	all[BUFFER_SIZE + 1];
	char		ret;
	int			flag;

	flag = 0;
	ret = NULL;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	while (all[0] || read(fd, all, BUFFER_SIZE) > 0)
	{
		ret = ft_backup(ret, &flag);
	}
}
