/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 20:37:20 by brsantsc          #+#    #+#             */
/*   Updated: 2024/11/20 00:18:40 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

static const char	*checker(const char *str)
{
	int			len;
	const char	*nbr;

	len = 0;
	while (is_space(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
		ft_putstr("Positive numbers please!");
	if (!is_digit(*str))
		ft_putstr("Digits please!");
	nbr = str;
	while (is_digit(*str++))
		len++;
	if (len > 10)
		ft_putstr("Value too big");
	return (nbr);
}

long	ft_atol(const char *str)
{
	long	nbr;

	nbr = 0;
	str = checker(str);
	if (str == NULL)
		return (-1);
	while (is_digit(*str))
	{
		nbr = (nbr * 10) + (*str - 48);
		if (nbr > INT_MAX)
		{
			ft_putstr("ERROR: Value too big");
			return (-1);
		}
		str++;
	}
	return (nbr);
}
/*#include <stdio.h>

int main(void)
{
    // Test 1: Valid input with leading spaces
    printf("Test 1: '   489'\n");
    printf("Result: %ld\n", ft_atol("   489"));
    printf("----------------------\n");

    // Test 2: Valid input with a leading '+'
    printf("Test 2: '   +123456789'\n");
    printf("Result: %ld\n", ft_atol("   +123456789"));
    printf("----------------------\n");

    // Test 3: Invalid input with a leading '-'
    printf("Test 3: '   -123456789' (Negative number not allowed)\n");
    printf("Result: %ld\n", ft_atol("   -123456789"));
    printf("----------------------\n");

    // Test 4: Maximum INT_MAX value (2147483647)
    printf("Test 4: '   2147483647' (Valid, INT_MAX)\n");
    printf("Result: %ld\n", ft_atol("   2147483647"));
    printf("----------------------\n");

    // Test 5: Just over INT_MAX (2147483648)
    printf("Test 5: '   2147483648' (Overflow, larger than INT_MAX)\n");
    printf("Result: %ld\n", ft_atol("   2147483648"));
    printf("----------------------\n");

    // Test 6: Valid input with leading zeroes
    printf("Test 6: '   0000123'\n");
    printf("Result: %ld\n", ft_atol("   0000123"));
    printf("----------------------\n");

    // Test 7: Invalid input with non-digit characters after the number
    printf("Test 7: '   123abc' (Invalid due to non-digit characters)\n");
    printf("Result: %ld\n", ft_atol("   123abc"));
    printf("----------------------\n");

    // Test 8: Invalid input with multiple '+' and '-' signs
    printf("Test 8: '+---   59751' (Invalid due to multiple signs)\n");
    printf("Result: %ld\n", ft_atol("+---   59751"));
    printf("----------------------\n");

    // Test 9: Input with more than 10 digits, should trigger "Value too big"
    printf("Test 9: '12345678901' (11 digits, too big)\n");
    printf("Result: %ld\n", ft_atol("12345678901"));
    printf("----------------------\n");

    // Test 10: Input with only spaces, should trigger "Digits only, please!"
    printf("Test 10: '   ' (Only spaces, invalid input)\n");
    printf("Result: %ld\n", ft_atol("   "));
    printf("----------------------\n");

    return 0;
}*/
