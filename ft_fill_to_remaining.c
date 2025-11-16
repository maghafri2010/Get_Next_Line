/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_to_remaining.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghafr <amaghafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:34:39 by mabdo             #+#    #+#             */
/*   Updated: 2025/11/16 10:40:18 by amaghafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_copy(char *remaining, int i, int len)
{
	char	*str;
	int		x;

	x = 0;
	if (i >= len)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(len - i + 1);
	if (!str)
		return (NULL);
	while (remaining[i])
		str[x++] = remaining[i++];
	str[x] = '\0';
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
		str = ft_copy(remaining, i + 1, len);
		free(remaining);
		return (str);
	}
	free(remaining);
	return (NULL);
}
