#include "get_next_line.h"

int main (int ac, char **av)
{
	(void)ac;
	int fd = open("leitura", O_RDONLY);
	char *string = get_next_line(fd);
	printf("%s\n", string);

	printf("%i", *(int *)(ft_strchr(av[1], 'd') + 0));
	free(string);
}