
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

//gcc -Wall -Wextra -Werror -Wl,--wrap=malloc -g *.c -o a.out
//valgrind --leak-check=full --track-origins=yes ./a.out test.txt

extern void* __real_malloc(size_t size);

void* __wrap_malloc(size_t size) 
{
    // Cambia el 3 por el número de mallocs exitosos que quieras permitir
    static int llamadas_exitosas = 3;

    if (llamadas_exitosas > 0) {
        llamadas_exitosas--;
        return __real_malloc(size); // Llama al malloc de verdad
    }
    
    return NULL; // A partir de la cuarta llamada, todas fallan
}

int	main (int argc, char **argv)
{
	if (argc == 1)
		return (0);
	int fd = open(argv[1], O_RDONLY);
	char *line = get_next_line(fd);
	int i = 0;
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
			i++;
		}
		free(line);
		line  = NULL;
		close(fd);
		return (0);
}