/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saperez- <saperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:49:51 by saperez-          #+#    #+#             */
/*   Updated: 2026/06/04 11:12:58 by saperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free_strjoin(char *save, char *tmp)
{
	char	*new;

	new = ft_strjoin(save, tmp);
	free(save);
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
	{
		free(save);
		return (NULL);
	}
	new_save = ft_calloc(ft_strlen(save) - i, sizeof(char));
	if (!new_save)
	{
		free(save);
		return (NULL);
	}
	i++;
	n = 0;
	while (save[i] != '\0')
		new_save[n++] = save[i++];
	free(save);
	return (new_save);
}

char	*make_line_from(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (save[i] == '\0')
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
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_until_enter(int fd, char *save)
{
	int		n_of_chars;
	char	*tmp;

	if (!save)
		save = ft_calloc(1, 1);
	if (!save)
		return (NULL);
	tmp = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!tmp)
		return (free(save), NULL);
	n_of_chars = 1;
	while (n_of_chars > 0)
	{
		n_of_chars = read(fd, tmp, BUFFER_SIZE);
		if (n_of_chars < 0)
			return (free(tmp), free(save), NULL);
		tmp[n_of_chars] = '\0';
		save = ft_free_strjoin(save, tmp);
		if (!save)
			return (free(tmp), NULL);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(tmp);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save[1024];

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = read_until_enter(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	line = make_line_from(save[fd]);
	if (line == NULL)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	save[fd] = the_rest(save[fd]);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>

int	main (int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	char *line = get_next_line(fd);
	char *line2 = get_next_line(fd2);
	int i = 0;
	while (line || line2)
	{
    	if (line)
        	printf("%s", line);
    	if (line2)
        	printf("%s", line2);

    	free(line);
    	free(line2);

    	line = get_next_line(fd);
    	line2 = get_next_line(fd2);
	}
		free(line);
		free(line2);
		line  = NULL;
		close(fd);
		close(fd2);
		return (0);
	// if (argc == 2)
	// {
		
	// }
	// else
	// 	return (0);
}