/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghafr <amaghafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:20:37 by mabdo             #+#    #+#             */
/*   Updated: 2025/11/16 10:58:46 by amaghafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
