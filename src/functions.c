/**
 * \file functions.c
 * \brief Declaration of functions
 * \author Pierre Carles
 *
 * All the non-solving functions are declared here.
 */

#include "header.h"

/**
 * \fn void ft_putchar(char c)
 * \brief Write a char.
 *
 * \param c The character to write.
 *
 * Write the character `c` in the stdout (standard output).
 */
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/**
 * \fn void ft_putstr(char *str)
 * \brief Write a string.
 *
 * \param str A pointer to a null-terminated array of char (string).
 *
 * Write the string pointed by str in the stdout (standard output).
 */
void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	write(1, str, i);
}

/**
 * \fn int **ft_init_grid(int size)
 * \brief Initialize a double dimension array of pointer.
 *
 * \param size The size of the expected array.
 * \return A pointer pointing the first element of the allocated array.
 *
 * Allocate a 2 dimensions array of int with malloc().
 */
int	**ft_init_grid(int size)
{
	int i, **grid;

	grid = malloc(sizeof(*grid) * size);
	for(i = 0; i < size; i++)
		grid[i] = malloc(sizeof(**grid) * size);
	return(grid);
}

/**
 * \fn void ft_free_grid(int **grid, int size)
 * \brief Free the pointed array.
 *
 * \param grid The grid to be freed.
 * \param size The size of the grid.
 *
 * Free the pointed array using free().
 */
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

/**
 * \fn void ft_set_grid(int **grid, char **argv)
 * \brief Set the numbers in the grid using argv.
 *
 * \param grid The grid to be set.
 * \param argv The input arguments.
 *
 * Set the input values contained in argv correctly in the grid.
 */
void	ft_set_grid(int **grid, char **argv)
{
	int x, y;

	for(x = 0; x < 9; x++)
	{
		for(y = 0; y < 9; y++)
		{
			if(argv[x + 1][y] == '.')
				grid[x][y] = 0;
			else
				grid[x][y] = argv[x + 1][y] - '0';
		}
	}
}

/**
 * \fn void ft_print_grid(int **grid)
 * \brief Display the grid.
 *
 * \param grid The grid to be displayed.
 *
 * Displays the int contained in grid int the stdout (standard output).
 */
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
