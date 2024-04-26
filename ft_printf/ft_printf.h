#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
void	ft_format(const char *format, void *arg);
void	ft_print_char(int c);
char	*make_string(unsigned int value, int *len);
int		ft_print_hex(unsigned int value, int ascii);
int		ft_print_nbr(int n);
int		ft_print_ptr(unsigned int value, int ascii);
int		ft_print_str(char *str);
void	print(unsigned int nb);
int		ft_print_unsigned(unsigned int nb);

#endif
