/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:29:00 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/09 18:57:46 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;

	ptr = *lst;
	while (ptr)
	{
		*lst = ptr;
		ptr = ptr->next;
		free(*lst);
	}
	*lst = NULL;
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	length;

	length = 0;
	while (src[length] != '\0')
		length++;
	i = 0;
	if (dstsize == 0)
		return (length);
	while ((src[i] != '\0') && (i < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (length);
}
