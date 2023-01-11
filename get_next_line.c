/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 21:47:28 by cmenke            #+#    #+#             */
/*   Updated: 2023/01/11 12:21:15 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read returns -1 if the buffer is not right.
// compare the buffer for \0 or \n

// -----------
//check the remainder

//read till NULL or \n

//check buffer for /n or null

//create the remainder

char	*ft_read_line(char **remainder, int fd, int *inf)
{
	char	*buffer;
	char	*temp;
	int		read_ret;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (!buffer || read_ret == -1)
		return (NULL);
	if (read_ret == 0)
		*inf = 0;
	else
	{
		if (*remainder)
		{
			temp = ft_strjoin(*remainder, buffer);
			free(*remainder);
		}
		else
			temp = ft_strjoin("", buffer);
		free(buffer);
		*remainder = temp;
	}
	return (*remainder);
}

char	*ft_check(char **remainder, int fd, int *inf)
{
	char	*spot;
	char	*result;
	char	*temp;

	result = NULL;
	spot = NULL;
	if (*remainder)
		spot = ft_strchr(*remainder, '\n');
	if (spot)
	{
		result = ft_substr(*remainder, 0, spot - *remainder + *inf);
		temp = ft_strjoin(spot + *inf, "");
		free(*remainder);
		*remainder = temp;
	}
	else if (!spot && *inf == 1)
	{
		if (ft_read_line(remainder, fd, inf))
			return (ft_check(remainder, fd, inf));
		else
			free(*remainder);
	}
	else if (*inf == 0)
	{
		result = *remainder;
		*remainder = NULL;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*result;
	int			inf;

	inf = 1;
	result = NULL;
	if (fd == -1)
		return (NULL);
	result = ft_check(&remainder, fd, &inf);
	if (inf == 0 || result == NULL)
		remainder = NULL;
	return (result);
}

// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// int main(void)
// {
// 	int fd;

// 	fd = open("lines.txt", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	close(fd);
// }