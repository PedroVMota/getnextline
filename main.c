#include "get_next_line.h"

int main ()
{
	system("clear");
	int fd = open("leitura.html", O_RDONLY);
	char *string = get_next_line(fd);
	printf("====== RESULT ======\n");
	printf("%s\n", string);
	free(string);
}