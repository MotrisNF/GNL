/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saperez- <saperez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 14:50:13 by saperez-          #+#    #+#             */
/*   Updated: 2026/06/17 11:50:46 by saperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned long int	ft_strlen(char *s)
{
	unsigned long int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *save, int character)
{
	int	i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i])
	{
		if (save[i] == (char)character)
			return (&save[i]);
		i++;
	}
	if (character == '\0')
		return (&save[i]);
	return (NULL);
}

char	*ft_free_all(char **save, char **line, char **tmp)
{
	if (save && *save)
	{
		free(*save);
		*save = NULL;
	}
	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	if (tmp && *tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	return (NULL);
}

void	*ft_calloc(unsigned long int size, unsigned long int c)
{
	char				*result;
	unsigned long int	i;

	result = malloc(size * c);
	if (!result)
		return (NULL);
	i = 0;
	while (i < size * c)
		result[i++] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
