/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 10:14:00 by ydumaine          #+#    #+#             */
/*   Updated: 2022/03/10 18:22:52 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		GET_NEXT_LINE_H
# define	GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char *get_next_line(int fd);
char *ft_extract_line(char *str_save);
char *ft_update_save(char *str_save);
size_t	ft_strlen(const char *s);
int	ft_strchr(const char *s, int c);
char	*ft_strjoin_andfreeS2(char const *s1, char const *s2);


#endif
