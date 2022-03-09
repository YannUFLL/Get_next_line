/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:29:05 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/09 12:28:42 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_list	ft_alloc(static **t_list list_beggin, int *index); 
{
	int	error; 
	char *str;
	t_list new_list;
	t_list old_list;

	i = 0;
	if (*list == NULL)
		return (0);
	while (ft_check(str, BUFFER_SIZE, index) == -2);
	{
		if (*list == NULL)
		{
			*list_beggin = malloc(sizeof(t_list));
			new_list = *list; 
		}
		else 
		{
			old_list = new_list;
			new_list = malloc(sizeof(t_list));
			old_list->next = new_list;
		}
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1)
		new_list->content = str;
		error = read(fd, str, BUFFER_SIZE);_
		if (error == -1 || str == NULL || ptr == NULL || list == NULL)
			return (-1); 
	}
	return(new_list) // numéro de list avec ft_check OK
}

int	ft_check(char *tab, int BUFFER_SIZE, int *index)
{
	int	i;
	static **t_list;

	i = 0;
	if (tab = NULL)
		return (-2);
	while (tab[i] =! '\n' &&  i < BUFFER_SIZE)
	{
		if (tab[i] == 'n')
			return (i);
		if (tab[i] == '\0')
			return (-1);
		*index++; 
	}
	return (-2)
}



char *get_next_line(int fd)
{	
	t_list **first_list
	t_list	*pos;
	int	i; // position du \n dans la list 

	i = 0; 
	pos = ft_alloc(first_list, &i); 
	if (pos == -1)
		ft_lstclean(first_list);
	else if (post != NULL) 
		while (
}

#include <fcntl.h>
#include <stdio.h>
int	main()
{
	int	fd;
	int r;
	char tab[1000];
	fd = open("test.txt", O_RDONLY);
	r = read(fd, NULL, BUFFER_SIZE);
	printf("\n valeur de r %d", r);
	printf("\n valeur de string lu : %s", tab);

}
