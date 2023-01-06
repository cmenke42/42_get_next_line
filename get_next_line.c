/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:47:28 by cmenke            #+#    #+#             */
/*   Updated: 2023/01/06 22:23:33 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void *get_line(char **remainder, char **result)
{

}

char	*get_next_line(int fd)
{
	static char *remainder;
	char *result;
	
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
	printf("%s\n", get_next_line(fd));
	close(fd);
}