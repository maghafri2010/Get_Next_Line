/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghafr <amaghafr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:44:41 by amaghafr          #+#    #+#             */
/*   Updated: 2025/11/14 11:57:28 by amaghafr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int pos;
    static char *leftover;
    char    *tmp;
    char *ptr;
    char buffer[BUFFER_SIZE + 1];
    int i;

    i = 0;

    if (fd <= 0)
        return NULL;
    
    if (BUFFER_SIZE <= 0)
        return NULL;

    if (!leftover)
    {
        leftover = malloc(1);
        leftover[0] = '\0';
    }
    if (leftover)
    {
        int x = ft_new_line(leftover);

        if (x == -1)
        {
            return leftover;
        }
       
        
        
        int left_len = ft_strlen(leftover);
        tmp = malloc(x + 2);
        ptr = malloc(left_len - x);
        if (!tmp)
            return NULL;
        while (i < x && leftover[i])
        {
            tmp[i] = leftover[i];
            i++;
        }
        tmp[i] = '\n';
        tmp[i + 1] = '\0';
    
        ptr = ft_strdup(leftover, x + 1);
        
        free(leftover);
        leftover = ptr;
        
    }
    return tmp;

    
    

 
    
    
}