#include "get_next_line.h"

int	main(void)
{
	int	fd;
	
	fd = open("/dev/stdin", O_RDONLY);
	printf("%s", get_next_line(fd));
}
