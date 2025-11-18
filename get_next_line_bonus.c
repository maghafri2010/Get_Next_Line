/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdo <mabdo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:44:41 by amaghafr          #+#    #+#             */
/*   Updated: 2025/11/18 12:00:05 by mabdo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_to_newline(char *remaining)
{
	int		i;
	char	*str;
	char	tmp;

	i = 0;
	if (!remaining)
		return (NULL);
	while (remaining[i] != '\n' && remaining[i])
		i++;
	if (remaining[i] == '\0')
		return (ft_strdup(remaining));
	tmp = remaining[i + 1];
	remaining[i + 1] = '\0';
	str = ft_strdup(remaining);
	remaining[i + 1] = tmp;
	return (str);
}

char	*ft_fill_remaining(char *remaining)
{
	char	*str;
	int		i;
	int		len;

	if (!remaining || !remaining[0])
	{
		free(remaining);
		return (NULL);
	}
	i = 0;
	len = ft_strlen(remaining);
	while (remaining[i] != '\n' && remaining[i])
		i++;
	if (remaining[i] == '\n')
	{
		if (i + 1 >= len)
			str = ft_strdup("");
		else
			str = ft_strdup(&remaining[i + 1]);
		free(remaining);
		return (str);
	}
	free(remaining);
	return (NULL);
}

int	ft_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_readline(char *remaining, int fd)
{
	ssize_t	pos;
	char	*tmp;
	char	buffer[BUFFER_SIZE + 1];

	if (!remaining)
		remaining = ft_strdup("");
	while (ft_new_line(remaining) == -1)
	{
		pos = read(fd, buffer, BUFFER_SIZE);
		if (pos < 0)
		{
			free(remaining);
			return (NULL);
		}
		if (pos == 0)
			break ;
		buffer[pos] = '\0';
		tmp = ft_strjoin(remaining, buffer);
		free(remaining);
		if (!tmp)
			return (NULL);
		remaining = tmp;
	}
	return (remaining);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remaining[1024];

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	remaining[fd] = ft_readline(remaining[fd], fd);
	if (!remaining[fd] || remaining[fd][0] == '\0')
	{
		free(remaining[fd]);
		remaining[fd] = NULL;
		return (NULL);
	}
	line = ft_fill_to_newline(remaining[fd]);
	remaining[fd] = ft_fill_remaining(remaining[fd]);
	return (line);
}
