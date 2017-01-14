#include "header.h"
#define DIM 9

int	main(int argc, char **argv)
{
	if(argc == 10)
	{
		int **grid = ft_init_grid(DIM);
		ft_set_grid(grid, argv);
		if(ft_check_grid(grid))
		{
			ft_solve(grid, 0);
			ft_print_grid(grid);
		}
		else
			ft_put_str("Erreur dans la grille\n");
		ft_free_grid(grid, DIM);
	}
	else
	{
		ft_put_str("Il faut entrer 9 arguments\n");
	}
}
