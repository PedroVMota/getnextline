/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:48:33 by pvital-m          #+#    #+#             */
/*   Updated: 2023/04/17 17:27:22 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*string;
	int		fd;

	system("clear");
	fd = open("vam", O_RDONLY);
	string = get_next_line(fd);
	printf(">%s", string);
	free(string);
}
