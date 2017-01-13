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
	{
		ft_putchar(str[i]);
	}
}

int	ft_set_grid(int **grid, char **argv)
{
	int x;
	int y;

	x = 0;
	while(x < 9)
	{
		y = 0;
		while(y < 9)
		{
			if(argv[x + 1][y] == '.')
				grid[x][y] = 0;
			else if(argv[x + 1][y] >= '1' && argv[x + 1][y] <= '9')
				grid[x][y] = argv[x + 1][y] - 48;
			else
				return(0);
			y++;
		}
		x++;
	}
	return(1);
}

void	ft_print_grid(int **grid)
{
	int x;
	int y;

	x = 0;
	while(x < 9)
	{
		y = 0;
		while(y < 9)
		{
			ft_putchar(grid[x][y] + 48);
			if(y != 8)
				ft_putchar(' ');
			y++;
		}
		ft_putchar('\n');
		x++;
	}
}
