/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mawelsch <mawelsch@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:52:46 by mawelsch          #+#    #+#             */
/*   Updated: 2025/10/23 16:39:22 by mawelsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*(char *)s = '\0';
		s++;
		n--;
	}
}

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
