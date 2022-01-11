#include "so_long.h"
#include "so_long_utils.h"

void	map_valid(char *av)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error("invalid file");
	
}