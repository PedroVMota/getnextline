/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvital-m <pvital-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:44:13 by pvital-m          #+#    #+#             */
/*   Updated: 2023/04/15 19:10:15 by pvital-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5

#endif


char	*get_next_line(int fd);

// Extras Functions
char		*ft_strchr(char *s, int c);
size_t	ft_strlen(const char *s);
char		*ft_strjoin(char *s1, char *s2);
char		*string_duplicate(char *content);
int		get_char_position(char *s, char c);
#endif