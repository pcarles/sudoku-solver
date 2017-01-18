#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_put_str(char *str);
int**	ft_init_grid(int dim);
void	ft_free_grid(int **grid, int dim);
int	ft_set_grid(int **grid, char **argv);
void	ft_print_grid(int **grid);
int	ft_check_argv(char **argv);
int	ft_check_grid(int **grid);
int	ft_check_column(int **grid, int *y, int *nb);
int	ft_check_line(int **grid, int *x, int *nb);
int	ft_check_block(int **grid, int *x, int *y, int *nb);
int	ft_solve(int **grid, int pos);

#endif
