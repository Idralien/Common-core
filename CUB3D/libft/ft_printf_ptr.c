
#include "ft_printf.h"

int	ft_pointer_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num > 15)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_pointer(unsigned long long num)
{
	int	ptr_len;

	ptr_len = 0;
	if (num == 0)
		ptr_len += write(1, "(nil)", 5);
	else
	{
		ptr_len += write(1, "0x", 2);
		ft_put_ptr(num);
		ptr_len += ft_pointer_len(num);
	}
	return (ptr_len);
}
