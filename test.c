/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:30:53 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/10 21:34:29 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int	fd;
	int	i;
	char str[10000];
	fd = open("test.txt", O_RDONLY);
	i = read(fd, str, BUFFER_SIZE);
	printf("\n valeur de str : %s", str);
	printf("\n valeur de read : %d", i);
}
