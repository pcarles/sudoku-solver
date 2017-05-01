/**
 * \file functions.c
 * \brief Declaration of functions
 * \author Pierre Carles
 *
 * All the non-solving functions are declared here.
 */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	write(1, str, i);
}

int	**ft_init_grid(int size)
{
	int i, **grid;

	grid = malloc(sizeof(*grid) * size);
	for(i = 0; i < size; i++)
		grid[i] = malloc(sizeof(**grid) * size);
	return(grid);
}

void	ft_free_grid(int **grid, int size)
{
	size--;
	while(size >= 0)
	{
		free(grid[size]);
		size--;
	}
	free(grid);
}

void	ft_set_grid(int **grid, char *str)
{
	int x, y;

	for(x = 0; x < 9; x++)
	{
		for(y = 0; y < 9; y++)
		{
			if(str[(9 * x) + y] == '.')
				grid[x][y] = 0;
			else
				grid[x][y] = str[(9 * x) + y] - '0';

		}
	}
}

void	ft_print_grid(int **grid)
{
	int x, y;

	for(x = 0; x < 9; x++)
	{
		for(y = 0; y < 9; y++)
		{
			ft_putchar(grid[x][y] + '0');
			if(y != 8)
			{
				if(y == 2 || y == 5)
					ft_putstr(" | ");
				else
					ft_putchar(' ');
			}
		}
		ft_putchar('\n');
		if(x == 2 || x == 5)
			ft_putstr("---------------------\n");
	}
}
