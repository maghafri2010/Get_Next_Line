/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghafr <amaghafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:41:59 by amaghafr          #+#    #+#             */
/*   Updated: 2025/11/14 12:12:23 by amaghafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static  int ft_strlen(char *str)
{
    int i = 0;

    while (str[i])
        i++;
    return(i);
}

static  int ft_new_line(char *str)
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

static char  *ft_strjoin(char *s1, char *s2)
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

static char **ft_split(char *str)
{
    char **array;
    int i;
    int n;
    int newline;
    int str_len;

    i = 0;
    n = 0;
    newline = ft_new_line(str);
    str_len = ft_strlen(str);
    array = malloc(2 * sizeof(char *));
    if (!array)
        return NULL;
    if (newline != -1)
        array[0] = malloc(newline + 2);
    else
        array[0] = malloc(str_len);
    if (!array[0])
    {
        free(array);
        return NULL;
    }
    
}
