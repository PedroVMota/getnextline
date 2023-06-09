/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:03:46 by pvital-m          #+#    #+#             */
/*   Updated: 2023/04/18 14:25:21 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	all[BUFFER_SIZE + 1];
	char		*ret;
	int			trigger;

	trigger = 0;
	ret = NULL;
	if (fd < 0 || fd > FOPEN_MAX || !BUFFER_SIZE)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (ft_null_content(all));
	while (all[0] || read(fd, all, BUFFER_SIZE) > 0)
	{
		ret = ft_backup(ret, all);
		static_manager(all, &trigger);
		if (trigger)
			break ;
	}
	return (ret);
}
