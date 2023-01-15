/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 11:52:31 by cmenke            #+#    #+#             */
/*   Updated: 2023/01/15 16:40:51 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, int *inf)
{
	char	*buffer;
	int		read_ret;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_ret = read(fd, buffer, BUFFER_SIZE);
	if (read_ret == -1)
	{
		free(buffer);
		return (NULL);
	}
	else if (read_ret == 0)
		*inf = 0;
	return (buffer);
}

char	*ft_return_line(char **remainder, int *inf, char *spot)
{
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	if (*remainder && *inf == 0)
		spot = ft_strchr(*remainder, '\0');
	line = ft_substr(*remainder, 0, spot - *remainder + *inf);
	if (line != NULL && *inf == 1)
		temp = ft_strjoin(spot + *inf, "");
	free(*remainder);
	*remainder = temp;
	return (line);
}

char	*ft_check_remainder(char **remainder, int fd, int *inf)
{
	char	*line;
	char	*temp;
	char	*spot;

	line = NULL;
	temp = NULL;
	spot = NULL;
	if (*remainder && *inf == 1)
		spot = ft_strchr(*remainder, '\n');
	if (!spot && *inf == 1)
	{
		line = ft_read_line(fd, inf);
		if (!line)
			return (NULL);
		temp = ft_strjoin(*remainder, line);
		if (!temp)
			return (NULL);
		free(*remainder);
		free(line);
		*remainder = temp;
		line = ft_check_remainder(remainder, fd, inf);
	}
	else
		line = ft_return_line(remainder, inf, spot);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			inf;

	inf = 1;
	line = NULL;
	if (fd == -1)
		return (NULL);
	if (remainder == NULL)
		remainder = ft_read_line(fd, &inf);
	if (remainder)
		line = ft_check_remainder(&remainder, fd, &inf);
	if (!line)
	{
		free(remainder);
		remainder = NULL;
	}
	return (line);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
// 	int fd;
// 	char *temp;

// 	fd = open("../lines.txt", O_RDONLY);

// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	free(temp);
// 	temp = get_next_line(fd);
// 	printf("%s", temp);
// 	free(temp);
// 	close(fd);
// }