#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_str(char *str)
{
	int i = 0;

	while(str[i])
		i++;
	write(1, str, i);
}

int	**ft_init_grid(int dim)
{
	int i;
	int **grid = malloc(sizeof(*grid) * dim);

	for(i = 0; i < dim; i++)
		grid[i] = malloc(sizeof(**grid) * dim);

	return(grid);
}

void	ft_free_grid(int **grid, int dim)
{
	dim--;
	while(dim >= 0)
	{
		free(grid[dim]);
		dim--;
	}
	free(grid);
}

int	ft_set_grid(int **grid, char **argv)
{
	int x;
	int y;

	for(x = 0; x < 9; x++)
	{
		for(y = 0; y < 9; y++)
		{
			if(argv[x + 1][y] == '.')
				grid[x][y] = 0;
			else if(argv[x + 1][y] >= '1' && argv[x + 1][y] <= '9')
				grid[x][y] = argv[x + 1][y] - '0';
			else
				return(0);
		}
	}
	return(1);
}

void	ft_print_grid(int **grid)
{
	int x;
	int y;

	for(x = 0; x < 9; x++)
	{
		for(y = 0; y < 9; y++)
		{
			ft_putchar(grid[x][y] + '0');
			if(y != 8)
			{
				if(y == 2 || y == 5)
					ft_put_str(" | ");
				else
					ft_putchar(' ');
			}
		}
		ft_putchar('\n');
		if(x == 2 || x == 5)
			ft_put_str("---------------------\n");
	}
}
