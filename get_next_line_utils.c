/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenke <cmenke@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:40:57 by cmenke            #+#    #+#             */
/*   Updated: 2023/01/15 16:44:25 by cmenke           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//allocates a memory of (count * size) and initialises it with 0.
//if allocation fails returns null.
//writes "n" zeroed bytes to the byte string *s.
//typecast so the system knows how big one byte is.
void	*ft_calloc(size_t count, size_t size)
{
	void			*result;
	unsigned char	*pointer;
	size_t			i;

	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	pointer = (unsigned char *)result;
	i = 0;
	while (i < count * size)
		pointer[i++] = '\0';
	return (result);
}

//returns NULL if malloc fails.
//else returns a new string (s1 + s2).
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	char	*new_string;
	int		i;
	int		j;

	total_length = ft_strlen(s1) + ft_strlen(s2);
	new_string = malloc((total_length + 1) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		new_string[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		new_string[j++] = s2[i++];
	new_string[j] = '\0';
	return (new_string);
}

//returns the length of a string without the terminating '\0'
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

//finds the first occurence of c (as char) in string *s including '\0'.
//returns address of occurence else NULL.
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*pointer;

	pointer = (char *)s;
	i = -1;
	while (pointer[++i] != '\0')
		if (pointer[i] == (char)c)
			return (&pointer[i]);
	if (pointer[i] == (char)c)
		return (&pointer[i]);
	return (NULL);
}

//*s is source from which to create the substring.
//start is the index of which to start in s.
// Return NULL if allocation fails else the substring.
// substring is at least
//(ft_Strlen(s) - start) if smaller len, or len.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	size_t			i;
	unsigned int	length;

	length = (unsigned int)ft_strlen(s);
	if (len == 0)
		return (NULL);
	if (start >= length)
		len = 0;
	else if (start < length)
		length = length - start;
	if (length < len)
		len = length;
	substring = malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	i = -1;
	while (++i < len && s[start + i] != '\0')
		substring[i] = s[start + i];
	substring[i] = '\0';
	return (substring);
}
