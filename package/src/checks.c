/**
 * \file checks.c
 * \brief Check functions
 * \author Pierre Carles
 *
 * Declaration of all the check functions.
 */

#include "header.h"

int	ft_check_str(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if(!(str[i] == '.' ||
		(str[i] >= '1' && 
		str[i] <= '9')))
			return(0);
		i++;
	}
	if(i != 81)
		return(0);
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
