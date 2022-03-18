/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:01:48 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/18 20:04:27 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*str_save[1025];
	char			*str_line;
	int				control;

	str_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	control = BUFFER_SIZE;
	while (ft_strchr(str_save[fd], 10) == -1 && control == BUFFER_SIZE)
	{
		str_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (str_line == NULL)
			return (NULL);
		control = read(fd, str_line, BUFFER_SIZE);
		if (ft_check_endfile(str_line, control))
			break ;
		str_line[control] = 0;
		str_save[fd] = ft_strjoin_andfree_s2(str_save[fd], str_line);
		free(str_line);
	}
	str_line = ft_extract_line(str_save[fd]);
	str_save[fd] = ft_update_save(str_save[fd]);
	return (str_line);
}

char	*ft_extract_line(char *str_save)
{
	char	*ptr;
	int		length;

	if (str_save == NULL)
		return (NULL);
	length = ft_strchr(str_save, 10);
	if (length == -1)
		length = ft_strlen(str_save);
	ptr = malloc(sizeof(char) * (length + 2));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, str_save, length + 2);
	return (ptr);
}

char	*ft_update_save(char *str_save)
{
	char	*ptr;
	int		j;
	int		i;

	i = ft_strchr(str_save, 10);
	if (i == -1)
	{
		free(str_save);
		return (NULL);
	}
	j = ft_strlen(str_save);
	if ((i + 1) == j)
	{
		free(str_save);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * ((j - (i + 1)) + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &str_save[i + 1], (j - (i + 1) + 1));
	free(str_save);
	return (ptr);
}
