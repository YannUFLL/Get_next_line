/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:29:05 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/08 23:41:40 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_stock(int fd) 
{
	char *str;
	static t_list list; 
	int	error;

	tab = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	list = malloc(sizeof(list)); 
	if (tab == NULL || list == NULL)
		return (NULL);
	error = read(fd, tab, BUFFER_SIZE);
	if (error = -1)
		return (NULL);
	list->content = tab;
	return (list);
}

int	ft_verify(char *tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (-1);
	while (tab[i] =! '\n' && tab[i])
	{
		if (tab[i] == 'n')
			return (i);
	}
	return (-1)
}



char *get_next_line(int fd)
{
	static t_list list; 
	while (ft_verif(t_list == -1))
	{
		list = ft_stock(int fd); 
		if (list == NULL)
			return (NULL);
	}
	
}

