/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 21:29:05 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/09 18:21:44 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
int	ft_check(char *tab, int *index)
{
	int	i;

	i = 0;
	printf("valeur tab[0] hors boucle : %c \n",tab[i]);
	printf("valeur adresse tab[0] hors boucle : %p \n",&tab[i]);
	while (tab[i] != '\n' &&  i < BUFFER_SIZE)
	{
		printf("valeur tab[i] : %c \n",tab[i]);
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
	printf("debut allocation \n");
	if (*list == NULL)
	{
		printf("creation premiere liste \n");
		*list = malloc(sizeof(t_list));
		new_list = *list;
	}
	while (c == -2)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		error = read(fd, str, BUFFER_SIZE);
		printf("lecture fichier et insertion adresse contenue dans liste \n");
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
	printf("FIN creation des tableau\n");
	return (*list); // numéro de list avec ft_check OK
}



char *get_next_line(int fd)
{	
	static t_list *first_list;
	static t_list	*list;
	char 	*str_cpy;
	char	*index_cpy;
	int	i; // position du \n dans la list

	i = 0;
	first_list = NULL;
	list = ft_alloc(&first_list, &i, fd);
	str_cpy = NULL;
	/*if (list == -1)
		ft_lstclear(first_list);*/
	printf("demarrage du processuce de copie");
	if (list != NULL)
	{
		printf("\nvaleur de i : %d", i);
		str_cpy = malloc(sizeof(char) * (i + 1));
		index_cpy = str_cpy;
		i = 0;
		while (list != NULL)
		{
			printf("\ncopie de list : %s ",list->content);
			printf("\nvaleur de i : %d", i);
			ft_strlcat(&str_cpy[i], list->content, (BUFFER_SIZE));
			i = i + BUFFER_SIZE;
			list = list->next;
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
