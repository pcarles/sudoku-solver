#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int**	ft_init_grid(int size);
void	ft_free_grid(int **grid, int size);
void	ft_set_grid(int **grid, char *str);
void	ft_print_grid(int **grid);
int	ft_check_str(char *str);
int	ft_check_grid(int **grid);
int	ft_check_column(int **grid, int *y, int *nb);
int	ft_check_line(int **grid, int *x, int *nb);
int	ft_check_block(int **grid, int *x, int *y, int *nb);
int	ft_solve(int **grid, int pos);

#endif
