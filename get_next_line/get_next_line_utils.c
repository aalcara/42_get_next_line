/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:59 by aalcara-          #+#    #+#             */
/*   Updated: 2021/03/03 22:22:06 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i) != '\0')
		i++;
	return (i);
}

void		*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*p;
	unsigned long	i;
	unsigned long	total;

	i = 0;
	total = nmemb * size;
	p = (unsigned char *)malloc(total);
	if (p == NULL)
		return (NULL);
	while (i < total)
	{
		*(p + i) = 0;
		i++;
	}
	return ((void *)p);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	unsigned int		s_len;
	unsigned int		real_len;
	char				*substr;

	if (s != NULL)
	{
		i = 0;
		real_len = len;
		s_len = ft_strlen(s);
		if (start >= s_len)
			return (substr = ft_calloc(1, sizeof(char)));
		if ((s_len - start) < len)
			real_len = (s_len - start);
		substr = ft_calloc(real_len + 1, sizeof(char));
		if (!substr)
			return (0);
		while (*(s + start + i) != '\0' && i < len)
		{
			*(substr + i) = *(s + i + start);
			i++;
		}
		return (substr);
	}
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		len;
	char				*substr;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(substr = malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		*(substr + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j) != '\0')
	{
		*(substr + i + j) = *(s2 + j);
		j++;
	}
	*(substr + i + j) = '\0';
	return (substr);
}
