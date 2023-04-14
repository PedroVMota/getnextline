#include "get_next_line.h"
#include "ft_colors.h"

int main (void)
{
	system("clear");
	int fd = open("leitura", O_RDONLY);

	char *string = get_next_line(fd);
	free(string);
}