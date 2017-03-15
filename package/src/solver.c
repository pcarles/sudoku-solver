/**
 * \file solver.c
 * \brief Solving functions.
 * \author Pierre Carles
 *
 * Declaration of all the solving functions.
 */

#include "header.h"

/**
 * \fn int ft_check_column(int **grid, int *y, int *nb)
 * \brief Check if a number is in a column of the grid.
 *
 * \param grid The grid to work on.
 * \param y The column to work on.
 * \param nb The number to be checked.
 * \return 0 if the number is in the column, 1 if it is not.
 *
 * Check if the number nb is in the column y of the grid.
 */
int	ft_check_column(int **grid, int *y, int *nb)
{
	int i;

	for(i = 0; i < 9; i++)
	{
		if(grid[i][(*y)] == (*nb))
			return(0);
	}
	return(1);
}

/**
 * \fn int ft_check_line(int **grid, int *x, int *nb)
 * \brief Check if a number is in a line of the grid.
 *
 * \param grid The grid to work on.
 * \param x The line to work on.
 * \param nb The number to be checked.
 * \return 0 if the number is in the line, 1 if it is not.
 *
 * Check if the number nb is in the column y of the grid.
 */
int	ft_check_line(int **grid, int *x, int *nb)
{
	int i;

	for(i = 0; i < 9; i++)
	{
		if(grid[(*x)][i] == (*nb))
			return(0);
	}
	return(1);
}

/**
 * \fn int ft_check_block(int **grid, int *x, int *y, int *nb)
 * \brief Check if a number is in a 3x3 block of the grid.
 *
 * \param grid The grid to work on.
 * \param y The column to work on.
 * \param x The line to work on
 * \param nb The number to be checked.
 * \return 0 if the number is in the block, 1 if it is not.
 *
 * Check if the number nb is on the 3x3 block positionned by x and y int the grid.
 */
int	ft_check_block(int **grid, int *x, int *y, int *nb)
{
	int i, j;

	for(i = (*y) - ((*y) % 3); i < (*y) - ((*y) % 3) + 3; i++)
	{
		for(j = (*x) - ((*x) % 3); j < (*x) - ((*x) % 3) + 3; j++)
		{
			if(grid[j][i] == (*nb))
				return(0);
		}
	}
	return(1);
}

/**
 * \fn int ft_solve(int **grid, int pos)
 * \brief Solve the grid.
 *
 * \param grid The grid to work on.
 * \param pos The position in the grid.
 * \return 1 if the grid is solved or 0 if th solver is blocked.
 *
 * Solve the sudoku grid using backtracking.
 */
int	ft_solve(int **grid, int pos)
{
	int x, y, i;

	x = pos / 9; /**< Extract the x position of pos */
	y = pos % 9; /**< Extract the y position of pos */
	if(pos == 81) /**< If we are at the end of the grid, return 1 */
		return(1);
	if(grid[x][y] != 0) /**< If it is already a number at this position, go to the next */
		return(ft_solve(grid, pos + 1));
	for(i = 1; i <= 9; i++) /**< Check all the possibility to put in (0-9) */
	{
		if(ft_check_column(grid, &y, &i) &&
		ft_check_line(grid, &x , &i) &&
		ft_check_block(grid, &x, &y, &i)) /**< If the number is valid, put it and check the next */
		{
			grid[x][y] = i;
			if(ft_solve(grid, pos + 1)) /**< If the next is the last and valid, we complete the sudoku, let's down the stack*/
				return(1);
		}
	}
	grid[x][y] = 0; /**< If we are blocked, put a zero and go back to try another number */
	return(0);
}
