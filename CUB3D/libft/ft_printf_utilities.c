#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_put_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_print_str(const char *str)
{
	int	i;

	if (str == NULL)
	{
		ft_put_str("(null)");
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_nbr(int n)
{
	size_t		len;
	char		*num;

	num = ft_itoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}
