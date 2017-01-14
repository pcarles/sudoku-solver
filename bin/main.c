#include "header.h"

int	main(int argc, char **argv)
{
	if(argc == 10)
	{
		int dim = 9;
		int **grid = ft_init_grid(dim);
		ft_set_grid(grid, argv);
		ft_solve(grid, 0);
		ft_print_grid(grid);
		ft_free_grid(grid, dim);
	}
}
