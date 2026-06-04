/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saperez- <saperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:50:27 by saperez-          #+#    #+#             */
/*   Updated: 2026/05/29 09:25:30 by saperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char				*the_rest(char *save);
char				*make_line_from(char *save);
char				*read_until_enter(int fd, char *save);
char				*get_next_line(int fd);
unsigned long int	ft_strlen(char *s);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strchr(char *save, int character);
void				*ft_calloc(unsigned long int size, unsigned long int c);
#endif