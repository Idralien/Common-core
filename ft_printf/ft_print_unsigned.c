#include "ft_printf.h"

void	print(unsigned int nb)
{
	if (nb > 9)
		ft_print_unsigned(nb / 10);
	if (nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	ft_putchar_fd((nb % 10) + 48, 1);
}

int	ft_print_unsigned(unsigned int nb)
{
	unsigned int	i;

	print(nb);
	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}
