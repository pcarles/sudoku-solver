#include "header.h"

int	ft_check_argv(char **argv)
{
	int i, j;

	j = 0;
	for(i = 1; i < 10; i++)
	{
		while(argv[i][j] && j < 10)
		{
			if(!(argv[i][j] == '.' ||
			(argv[i][j] >= '1' && 
			argv[i][j] <= '9')))
				return(0);
			j++;
		}
		if(j != 9)
			return(0);
		j = 0;
	}
	return(1);
}

int	ft_check_grid(int **grid)
{
	int x, y, nb;

	for(x = 0; x < 9; x++)
	{
		for(y = 0; y < 9; y++)
		{
			if(grid[x][y] != 0)
			{
				nb = grid[x][y];
				grid[x][y] = 0;
				if(!(ft_check_column(grid, &y, &nb) &&
				ft_check_line(grid, &x, &nb) &&
				ft_check_block(grid, &x, &y, &nb)))
				{
					grid[x][y] = nb;
					return(0);
				}
				grid[x][y] = nb;
			}
		}
	}
	return(1);
}
