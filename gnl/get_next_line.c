/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saperez- <saperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:49:51 by saperez-          #+#    #+#             */
/*   Updated: 2026/06/17 11:44:42 by saperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_free_strjoin(char *save, char *tmp)
{
	char	*new;

	new = ft_strjoin(save, tmp);
	ft_free_all(&save, NULL, NULL);
	if (!new)
		return (NULL);
	return (new);
}

char	*the_rest(char *save)
{
	int		i;
	int		n;
	char	*new_save;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
		return (ft_free_all(&save, NULL, NULL));
	new_save = ft_calloc(ft_strlen(save) - i, sizeof(char));
	if (!new_save)
		return (ft_free_all(&save, NULL, NULL));
	i++;
	n = 0;
	while (save[i] != '\0')
		new_save[n++] = save[i++];
	ft_free_all(&save, NULL, NULL);
	return (new_save);
}

char	*make_line_from(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save || save[i] == '\0')
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_until_enter(int fd, char *save)
{
	ssize_t	n_of_chars;
	char	*tmp;

	if (!save)
		save = ft_calloc(1, 1);
	if (!save)
		return (NULL);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (ft_free_all(&save, NULL, NULL));
	n_of_chars = 1;
	while (n_of_chars > 0)
	{
		n_of_chars = read(fd, tmp, BUFFER_SIZE);
		if (n_of_chars < 0)
			return (ft_free_all(&save, NULL, &tmp));
		tmp[n_of_chars] = '\0';
		save = ft_free_strjoin(save, tmp);
		if (!save)
			return (ft_free_all(NULL, NULL, &tmp));
		if (ft_strchr(save, '\n'))
			break ;
	}
	ft_free_all(NULL, NULL, &tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_until_enter(fd, save);
	if (save == NULL)
		return (NULL);
	line = make_line_from(save);
	if (line == NULL)
		return (ft_free_all(&save, NULL, NULL));
	save = the_rest(save);
	return (line);
}
