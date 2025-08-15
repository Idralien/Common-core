
#include "ft_printf.h"

int	ft_unbr_len(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int nb)
{
	int		len;
	char	*num;

	len = ft_unbr_len(nb);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (nb != 0)
	{
		num[len - 1] = nb % 10 + 48;
		nb /= 10;
		len--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int num)
{
	int		len;
	char	*uitoa_value;

	len = 0;
	if (num == 0)
		len += write(1, "0", 1);
	else
	{
		uitoa_value = (char *)ft_uitoa(num);
		len += ft_print_str(uitoa_value);
		free(uitoa_value);
	}
	return (len);
}
