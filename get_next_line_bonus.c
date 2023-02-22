/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tidigov <tidigov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:29:04 by tidigov           #+#    #+#             */
/*   Updated: 2022/01/05 17:40:32 by tidigov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_first_line(int fd, char *save_line)
{
	int		bytelu;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytelu = 1;
	while (!ft_strchr(save_line, '\n') && bytelu != 0)
	{
		bytelu = read(fd, buf, BUFFER_SIZE);
		if (bytelu <= -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytelu] = '\0';
		save_line = ft_strjoin(save_line, buf);
	}
	free(buf);
	return (save_line);
}

char	*ft_cleanline(char *s)
{
	int		a;
	char	*line;

	a = 0;
	if (s[0] == '\0')
		return (NULL);
	while (s[a] != '\n' && s[a])
		a++;
	line = (char *)malloc(sizeof(char) * (a + 1));
	if (!line)
		return (NULL);
	a = 0;
	while (s[a] && s[a] != '\n')
	{
		line[a] = s[a];
		a++;
	}
	if (s[a] == '\n')
	{
		line[a] = s[a];
		a++;
	}
	line[a] = '\0';
	return (line);
}

char	*ft_saveline(char *s)
{
	int		a;
	int		i;
	char	*line;

	a = 0;
	i = 0;
	while (s[a] && s[a] != '\n')
		a++;
	if (!s[a])
	{
		free(s);
		return (NULL);
	}
	line = (char *)malloc(ft_strlen(s) - a + 1);
	if (!line)
		return (NULL);
	a++;
	i = 0;
	while (s[a])
		line[i++] = s[a++];
	line[i] = '\0';
	free(s);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save_line[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save_line[fd] = ft_first_line(fd, save_line[fd]);
	if (!save_line[fd])
		return (NULL);
	line = ft_cleanline(save_line[fd]);
	save_line[fd] = ft_saveline(save_line[fd]);
	return (line);
}
