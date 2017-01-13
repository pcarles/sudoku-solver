#ifndef HEADER_H
# define HEADER_H

# include "unistd.h"

void	ft_putchar(char c);
void	ft_putstr(char *str);
int	ft_set_grid(int **grid, char **argv);
void	ft_print_grid(int **grid);
int	ft_check_colum(int **grid, int y, int nb);
int	ft_check_line(int **grid, int x, int nb);
int	ft_check_block(int **grid, int x, int y, int nb);
int	ft_solver(int **grid, int pos);

#endif
