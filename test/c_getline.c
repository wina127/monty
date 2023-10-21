#include <stdio.h>
#include <stdlib.h>

/**
 * custom_getline - Read a line from a stream
 * @lineptr: A pointer to the buffer where the line is stored
 * @n: A pointer to the size of the buffer
 * @stream: The input stream to read from
 * 
 * Return: The number of characters read, excluding null-terminator,
 *         or -1 on error
 */
size_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
    size_t pos = 0;
    int c;
    char *new_ptr;

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128; /* Initial buffer size */
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL)
        {
            return -1; /* Memory allocation error */
        }
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (pos >= *n - 1)
        {
            *n *= 2; /* Double the buffer size */
            new_ptr = (char *)realloc(*lineptr, *n);
            if (new_ptr == NULL)
            {
                return -1; /* Memory allocation error*/
            }
            *lineptr = new_ptr;
        }
        
        (*lineptr)[pos++] = c;

        if (c == '\n')
        {
            break;
        }
    }

    (*lineptr)[pos] = '\0'; /* Null-terminate the string */
    return (pos); /* Return the number of characters read (excluding null-terminator) */
}

