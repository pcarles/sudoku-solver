/**
 * \file header.h
 * \brief Header file
 * \author Pierre Carles
 *
 * Protyp of all fucntions.
 */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

/**
 * \fn int **ft_init_grid(int size)
 * \brief Initialize a double dimension array of pointer.
 *
 * \param size The size of the expected array.
 * \return A pointer pointing the first element of the allocated array.
 *
 * Allocate a 2 dimensions array of int with malloc().
 */
int**	ft_init_grid(int size);

/**
 * \fn void ft_free_grid(int **grid, int size)
 * \brief Free the pointed array.
 *
 * \param grid The grid to be freed.
 * \param size The size of the grid.
 *
 * Free the pointed array using free().
 */
void	ft_free_grid(int **grid, int size);

/**
 * \fn void ft_set_grid(int **grid, char *str)
 * \brief Set the numbers in the grid using a string.
 *
 * \param grid The grid to be set.
 * \param str The input arguments.
 *
 * Set the input values contained in str correctly in the grid.
 */
void	ft_set_grid(int **grid, char *str);

/**
 * \fn int ft_check_grid(int **grid)
 * \brief Check validity of the grid.
 *
 * \param grid The grid o be checked.
 *
 * Check if the grid is valid (2 numbers on the same column, line, block).
 */
int	ft_check_grid(int **grid);

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
int	ft_check_column(int **grid, int *y, int *nb);

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
int	ft_check_line(int **grid, int *x, int *nb);

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
int	ft_check_block(int **grid, int *x, int *y, int *nb);

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
int	ft_solve(int **grid, int pos);

#endif
