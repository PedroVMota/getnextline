#include "get_next_line.h"

int main ()
{
	system("clear");
	int fd = open("vam", O_RDONLY);
	char *string = get_next_line(fd);
	printf("%s", string);
	free(string);
}