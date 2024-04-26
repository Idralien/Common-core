#include "ft_printf.h"

void	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
}

void	ft_format(const char *format, void *arg)
{
	int	i;

	i = 0;
	if (format[i] == 'c')
		ft_print_char((long)arg);
	else if (format[i] == 's')
		ft_print_str((char *)arg);
	else if (format[i] == 'p')
		ft_print_ptr((unsigned long)arg, 87);
	else if (format[i] == 'd' || format[i] == 'i')
		ft_print_nbr((long)arg);
	else if (format[i] == 'u')
		ft_print_unsigned((unsigned long)arg);
	else if (format[i] == 'x' || format[i] == 'X')
	{
		if (format[i] == 'x')
			ft_print_hex((unsigned long)arg, 87);
		else if (format[i] == 'X')
			ft_print_hex((unsigned long)arg, 55);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	size_t		i;

	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX", str[i]))
				ft_format(str, va_arg(args, void *));
			else if (str[i] == '%')
				ft_print_char('%');
			i++;
		}
		else
			ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (i);
}
