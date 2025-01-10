/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angellop <angellop@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:17:57 by angellop          #+#    #+#             */
/*   Updated: 2025/01/10 14:49:47 by angellop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	ssize_t	bytes_read;
	
	// bytes_read = read(fd, buf, );

	if (fd == -1)
		return (NULL);

	while(bytes_read = read(fd, buf, BUFFER_SIZE) > 0)
	{
		
	}
	return ("");
}
