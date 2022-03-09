/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:29:05 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/09 19:35:21 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
int	ft_check(char *tab, int *index)
{
	int	i;

	i = 0;
	while (tab[i] != '\n' &&  i < BUFFER_SIZE)
	{
		if (tab[i] == '\n')
			return (i);
		if (tab[i] == '\0')
			return (-1);
		(*index)++;
	   	i++;	
	}
	return (-2);
}
// creation d une liste de tab de buffer tant que pas de \n
t_list	*ft_alloc(t_list **list, int *index, int fd)
{
	int	error;
	char *str;
	t_list *new_list;
	t_list *old_list;
	int	c;

	c = -2;
	new_list = NULL;
	if (*list == NULL)
	{
		*list = malloc(sizeof(t_list));
		new_list = *list;
	}
	while (c == -2)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		error = read(fd, str, BUFFER_SIZE);
		new_list->content = str;
		c = ft_check(new_list->content, index);
	   	if (c == -2)
		{	
			old_list = new_list;
			new_list = malloc(sizeof(t_list));
			old_list->next = new_list;
		}
		if (error == -1 || *list == NULL || new_list == NULL || str == NULL)
			return (NULL);
	}
	return (*list); // numéro de list avec ft_check OK
}



char *get_next_line(int fd)
{	
	static t_list 	*pos;
	t_list	*list;
	char 	*str_cpy;
	char	*index_pos;
	int	i; //position du \n dans la list
	int	u; //memoire fin de la string

	i = 0;
	u = 0;
	first_list = NULL;
	list = ft_alloc(&first_list, &i, fd);
	str_cpy = NULL;
	if (list != NULL)
	{
		str_cpy = malloc(sizeof(char) * (i + 1));
		index_pos = str_cpy;
		while (list != NULL)// creation de la ligne a envoyer 
		{
			if (i > BUFFER_SIZE)
			{
				ft_strlcat(&str_cpy[u], list->content, (BUFFER_SIZE));
				i = i - BUFFER_SIZE
				list = list->next;
				free list->content;
				free ->list;
			}
			if (i < BUFFER_SIZE && i > 0)
			{
				ft_strlcat(&str_cpy[u], list->content, i);
			}
			u = u + BUFFER_SIZE;
		}
	}
	return (str_cpy);
}

#include <fcntl.h>

int	main()
{
	int	fd;
	char *str;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("\n valeur de line : %s", str);
}
