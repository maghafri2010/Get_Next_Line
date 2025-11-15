/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_to_newline.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdo <mabdo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:13:36 by mabdo             #+#    #+#             */
/*   Updated: 2025/11/15 15:41:56 by mabdo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_fill(char *remaining, char *str)
{
	int	j;

	j = 0;
	while (remaining[j] && remaining[j] != '\n')
	{
		str[j] = remaining[j];
		j++;
	}
	if (remaining[j] == '\n')
	{
		str[j] = '\n';
		j++;
	}
	str[j] = '\0';
}

char	*ft_fill_to_newline(char *remaining)
{
	int		i;
	char	*str;

	i = 0;
	if (!remaining)
		return (NULL);
	while (remaining[i] != '\n' && remaining[i])
		i++;
	if (remaining[i] == '\n')
		str = malloc(i + 2);
	else
		str = malloc(i + 1);
	if (!str)
		return (NULL);
	ft_fill(remaining, str);
	return (str);
}
