#include "ft_printf.h"

int	print_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("null", 1);
		return (4);
	}
	while (str[i] != '\0')
		i++;
	ft_putstr_fd(str, 1);
	return (i);
}
