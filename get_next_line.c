/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:47:28 by cmenke            #+#    #+#             */
/*   Updated: 2023/01/07 16:01:43 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// compare the buffer for \0 or \n

// -----------
//check the remainder

//read till NULL or \n

//check buffer for /n or null

//create the remainder

char	*get_next_line(int fd)
{
	static char *remainder;
	
	if (fd == -1)
		return (NULL);
}

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
	int fd;
	
	fd = open("lines.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
}