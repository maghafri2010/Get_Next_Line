#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *get_next_line(int fd);
int ft_strlen(char *str);
int ft_new_line(char *str);
char    *ft_strjoin(char *s1, char *s2);
char *ft_strdup(char *str);
char *ft_readline(char *remaining, int fd);
char *ft_fill_to_newline(char *remaining);
char *ft_fill_remaining(char *remaining);


#endif
#endif