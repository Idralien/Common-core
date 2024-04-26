#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	int				nbr;
	unsigned int	i;

	nbr = n;
	i = 1;
	if (n < 0 && n != -2147483648)
	{
		nbr = -n;
		i++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	ft_putnbr_fd(n, 1);
	if (n == -2147483648)
		return (11);
	return (i);
}
