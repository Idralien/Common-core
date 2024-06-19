/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:36:16 by brsantsc          #+#    #+#             */
/*   Updated: 2024/05/02 09:19:52 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*De +48 zorgt ervoor dat het in de ascii waarden van decimalen gezet word.
De +ascii is voor het converten naar lowercase of uppercase 
dit is bijna altijd 87 voor uppercase en 55 voor lowercase.
Als de !value niet van bovem staat dan gaat er memory verloren.*/
#include "ft_printf.h"

static char	*make_string(unsigned long value, int *len)
{
	int				i;
	unsigned long	tmp;
	char			*str;

	i = 0;
	tmp = value;
	while (tmp != 0)
	{
		tmp = tmp / 16;
		i++;
	}
	str = ft_calloc(i + 1, sizeof(char));
	*len = i - 1;
	return (str);
}

int	ft_print_ptr(unsigned long value, int ascii)
{
	unsigned long	tmp_value;
	char			*print;
	int				i;

	if (!value)
		return (ft_putstr_fd("(nil)", 1), 5);
	tmp_value = value;
	print = make_string(value, &i);
	if (!print)
		return (0);
	while (tmp_value != 0 && i-- >= 0)
	{
		if ((tmp_value % 16) < 10)
			print[i + 1] = (tmp_value % 16) + 48;
		else
			print[i + 1] = (tmp_value % 16) + ascii;
		tmp_value = tmp_value / 16;
	}
	i = ft_strlen(print);
	i = i + ft_print_str("0x");
	ft_putstr_fd(print, 1);
	free(print);
	if (value == 0)
		i = i + ft_print_char('0');
	return (i);
}
