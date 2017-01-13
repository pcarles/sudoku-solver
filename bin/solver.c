/* return 0 if the number "nb" is in the column "y" of the grid */
int	ft_check_column(int **grid, int y, int nb)
{
	int i;

	i = 0;
	while(i < 9)
	{
		if(grid[i][y] == nb)
			return(0);
		i++;
	}
	return(1);
}

/* return 0 if the number "nb" is in the line "x" of the grid */
int	ft_check_line(int **grid, int x, int nb)
{
	int i;

	i = 0;
	while(i < 9)
	{
		if(grid[x][i] == nb)
			return(0);
		i++;
	}
	return(1);
}

/* return 0 if the number "nb" is in the 3x3 block of his position */
int	ft_check_block(int **grid, int x, int y, int nb)
{
	x = x - (x % 3);
	y = y - (y % 3);
	while(y < (y + 3))
	{
		while(x < (x + 3))
		{
			if(grid[x][y] == nb)
				return(0);
			x++;
		}
		x -= 3;
		y++;
	}
	return(1);
}

/* solver algorithm */
int	ft_solver(int **grid, int pos)
{
	int x;
	int y;
	int i;

	i = 1;
	x = pos / 9;
	y = pos % 9;
	if(pos == 81)
		return(1);
	if(grid[x][y] != 0)
		return(ft_solver(grid, pos + 1));
	while(i <= 9)
	{
		if(ft_check_column(grid, y, i) &&
		ft_check_line(grid, x , i) &&
		ft_check_block(grid, x, y, i))
		{
			grid[x][y] = i;
			if(ft_solver(grid, pos + 1))
				return(1);
		}
		i++;
	}
	grid[x][y] = 0;
	return(0);
}
