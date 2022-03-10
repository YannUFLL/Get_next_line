/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:01:48 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/10 21:49:24 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	static char		*str_save;
	char 			*str_line;
	int				control;
	

	str_save = NULL; 
	str_line = NULL;
	printf("OK");
	while (ft_strchr(str_save, 10) == -1 && control == BUFFER_SIZE)
	{
		str_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (str_line == NULL)
			return (NULL);
		control = read(fd, str_line, BUFFER_SIZE);
		str_line[control] = 0; 
		printf("valeur de control : %d ", control);
		printf("str_line : %s ", str_line);
		str_save = ft_strjoin_andfreeS2(str_line, str_save);
	}
	str_line = ft_extract_line(str_save);
	str_save = ft_update_save(str_save);
	if (str_save == NULL || str_line == NULL)
		return (NULL);
	return (str_line);
}

char *ft_extract_line(char *str_save)
{
	char *ptr;
	int	length;

	length = ft_strchr(str_save, 10);
	ptr = malloc(sizeof(char) * (length + 2));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, str_save, length + 1);
	return (ptr); 
}


char *ft_update_save(char *str_save)
{
	char *ptr;
	int j;
	int	i;

	i = ft_strchr(str_save, 10);
	j = ft_strlen(str_save);
	ptr = malloc(sizeof(char) * ((j - (i + 1)) + 1)); 
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, &str_save[i + 1], (j - (i + 1)));
	free(str_save);
	return (ptr);
}
#include <fcntl.h>
int	main()
{
	printf("OK");
	int	fd;
	char *str;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("\n valeur de line : %s", str);
}
