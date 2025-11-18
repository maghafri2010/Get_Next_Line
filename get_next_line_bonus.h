/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdo <mabdo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 15:17:55 by mabdo             #+#    #+#             */
/*   Updated: 2025/11/18 11:54:48 by mabdo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_new_line(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *str);
char	*ft_readline(char *remaining, int fd);
char	*ft_fill_to_newline(char *remaining);
char	*ft_fill_remaining(char *remaining);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strcat(char *s1, char *s2);

#endif
