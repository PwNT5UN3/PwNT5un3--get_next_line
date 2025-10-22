/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:48:11 by mawelsch          #+#    #+#             */
/*   Updated: 2025/10/22 16:12:41 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000000
#endif

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*address;
	char	*start;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	address = malloc(len);
	if (address == NULL)
		return (NULL);
	start = address;
	while (*s1 != '\0')
	{
		*address = *s1;
		address++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*address = *s2;
		address++;
		s2++;
	}
	*address = '\0';
	return (start);
}

char	*ft_strchr(const char *s, int c)
{
	void			*tmp;
	unsigned char	target;

	target = c;
	while (*s != '\0')
	{
		if (*s == target)
		{
			tmp = (void *)s;
			return (tmp);
		}
		s++;
	}
	if (*s == target)
	{
		tmp = (void *)s;
		return (tmp);
	}
	return (NULL);
}

char	*end_nl(char *total, char **left, char *buffer)
{
	int		index;
	int		index_2;
	char	*retstr;
	int		index_left;

	index = 0;
	index_2 = 0;
	index_left = 0;
	while (total[index] != '\n')
		index++;
	retstr = malloc(index + 2);
	if (retstr == NULL)
		return (NULL);
	while (index_2 <= index)
	{
		retstr[index_2] = total[index_2];
		index_2++;
	}
	retstr[index_2] = '\0';
	free(*left);
	while (total[index_2] != '\0')
		index_2++;
	if (index_2 > (index + 1))
	{
		*left = malloc(index_2 - index);
		if (*left == NULL)
			return (NULL);
		while (index_2 >= ++index)
		{
			*left[index_left] = total[index];
			index_left++;
		}
	}
	else
		*left = NULL;
	free(total);
	free(buffer);
	return (retstr);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			bytes_read;
	char		*total;
	static char	*left = NULL;
	char		*tmp;

	total = left;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (total != NULL)
		if (ft_strchr(total, '\n') != NULL)
			return (end_nl(total, &left, buffer));
	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (total != NULL)
		{
			tmp = ft_strjoin(total, buffer);
			if (tmp == NULL)
				return (NULL);
			free(total);
			total = tmp;
		}
		else
			total = ft_strjoin("", buffer);
		if (ft_strchr(buffer, '\n') != NULL)
			return (end_nl(total, &left, buffer));
	}
	free(buffer);
	return (total);
}

// int	main(void)
// {
// 	int	fd;

// 	fd = open("new.txt", O_RDONLY);
// 	printf("%s", get_next_line(fd));
// 	printf("\n%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// }
