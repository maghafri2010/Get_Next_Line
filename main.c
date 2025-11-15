#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    char *line;

    while ((line = get_next_line(0)) != NULL)
    {
        printf("%s", line); // prints the line including '\n'
        free(line);
    }

    return 0;
}