/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:27:32 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/22 15:35:16 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include "./libft/libft.h"

void	ft_puthex(unsigned int n, int uppercase);
void	ft_format(va_list args, const char *format);
void	ft_putunsigned(unsigned int n);
void	ft_printf_char(char c);
void	ft_printf_str(char *s);
int	ft_printf_ptr(unsigned int value, int asc);
int	ft_printf(const char *str);

#endif
