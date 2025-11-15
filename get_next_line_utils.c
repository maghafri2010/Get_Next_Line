/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghafr <amaghafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:59 by amaghafr          #+#    #+#             */
/*   Updated: 2025/11/15 10:45:11 by amaghafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return(i);
}

int ft_new_line(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] == '\n')
            return i;
        i++;
    }
    return -1;
}

char    *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int x = 0;

    if (!s1 && !s2)
        return NULL;
    if (!s1)
        return ft_strdup(s2);
    if (!s2)
        return ft_strdup(s1);

    int s1_len = ft_strlen(s1);
    int s2_len = ft_strlen(s2);
    char *str;

    str = malloc(s1_len + s2_len + 1);
    if (!str)
        return NULL;
    
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[x])
    {
        str[i + x] = s2[x];
        x++;
    }
    str[i + x] = '\0';
    return str;
    
}

char *ft_strdup(char *str)
{
    char *string;
    int x;
    int i;

    if (!str)
        return NULL;
    x = ft_strlen(str);
    string = malloc(x + 1);
    if (!string)
        return NULL;
    i = 0;
    while (str[i])
    {
        string[i] = str[i];
        i++;
    }
    string[i] = '\0';
    return (string);
}

char *ft_readline(char *remaining, int fd)
{
    int     pos;
    char    *tmp;
    char    buffer[BUFFER_SIZE + 1];
    
    if (!remaining)
        return ft_strdup("");
    while (ft_new_line(remaining) == -1)
    {
        pos = read(fd, buffer, BUFFER_SIZE);
        if (pos <= 0)
            break;
        buffer[pos] = '\0';
        tmp = ft_strjoin(remaining, buffer);
        free(remaining);
        remaining = tmp;
    }
    return remaining;
}


char *ft_fill_to_newline(char *remaining)
{
    int     i;
    int     j;
    char    *str;

    j = 0;
    i = 0;
    if (!remaining)
        return NULL;
    while (remaining[i] != '\n' && remaining[i])
        i++;
    if (remaining[i] == '\n')
        str = malloc(i + 2);
    else
        str = malloc(i + 1);
    if (!str)
        return NULL;
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
    return (str);
}

char *ft_fill_remaining(char *remaining)
{
    char    *str;
    int     i;
    int     len;
    int     x;

    x = 0;
    len = ft_strlen(remaining);
    i = 0;
    if (!remaining)
        return NULL;
    if (!remaining[i])
    {
        free(remaining);
        return NULL;
    }
    while (remaining[i] != '\n' && remaining[i])
        i++;
    if (remaining[i] == '\n')
    {
        i++;
        str = malloc(len - i + 1);
        if (!str)
            return NULL;
        while (remaining[i])
            str[x++] = remaining[i++];
        str[x] = '\0';
        free(remaining);
        return str;
    }
    free(remaining);
    return NULL;
}

