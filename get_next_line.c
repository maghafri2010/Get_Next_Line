/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghafr <amaghafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:44:41 by amaghafr          #+#    #+#             */
/*   Updated: 2025/11/15 10:44:41 by amaghafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int len;
    char *line;
    static char *remaining;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    remaining = ft_readline(remaining, fd);
    if (!remaining)
        return NULL;
    
    line = ft_fill_to_newline(remaining);
    remaining = ft_fill_remaining(remaining);

    return line;    
}