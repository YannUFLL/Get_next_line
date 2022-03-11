/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:29:00 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/11 15:07:36 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i++])
		;
	return (i - 1);
}
int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin_andfreeS2(char const *s1, char *s2)
{
	char	*ptr;
	size_t	size;
	int		i;
	
	size = ft_strlen(s1);
	size = size + ft_strlen(s2);
	ptr = malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	size = i;
	i = 0;
	if (s2 != NULL)
	{
		while (s2[i])
		{
			ptr[size + i] = s2[i];
			i++;
		}
	}
	free(s2);
	ptr[size + i] = 0;
	printf("\n valeur de string dans fonction : %s", ptr); 
	return (ptr);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	length;

	length = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (src[length] != '\0')
		length++;
	i = 0;
	if (dstsize == 0)
		return (length);
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (length);
}


