/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysoyturk <ysoyturk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:32:17 by ysoyturk          #+#    #+#             */
/*   Updated: 2025/03/21 21:41:08 by ysoyturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_write_line(char *letter)
{
	int		i;
	char	*line;

	i = 0;
	if (!letter[i])
		return (NULL);
	while (letter[i] != '\0' && letter[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (letter[i] != '\0' && letter[i] != '\n')
	{
		line[i] = letter[i];
		i++;
	}
	if (letter[i] == '\n')
	{
		line[i] = letter[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_after_line(char *letter)
{
	int		i;
	int		j;
	char	*after_line;

	j = 0;
	i = 0;
	while (letter[i] != '\0' && letter[i] != '\n')
		i++;
	if (!letter[i])
	{
		free(letter);
		return (NULL);
	}
	after_line = malloc(sizeof(char) * (ft_strlen2(letter) - i + 1));
	if (!after_line)
		return (NULL);
	i++;
	while (letter[i] != '\0')
		after_line[j++] = letter[i++];
	after_line[j] = '\0';
	free(letter);
	return (after_line);
}

char	*ft_read_fd(int fd, char *str)
{
	char	*buff;
	int		reader;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	reader = 1;
	while (!ft_strchr2(str, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[reader] = '\0';
		str = ft_strjoin2(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_fd(fd, str);
	if (!str)
		return (NULL);
	line = ft_write_line(str);
	str = ft_after_line(str);
	return (line);
}
