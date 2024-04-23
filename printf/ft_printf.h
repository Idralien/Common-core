/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 08:27:32 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/23 12:54:26 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

int		ft_printhex(unsigned long nbr, const char format);
void	ft_format(va_list args, const char *format);
void	ft_putunsigned(unsigned int n);
void	ft_printf_char(int c);
void	ft_printf_str(char *s);
int		ft_printf_ptr(unsigned int value, int asc);
int		ft_printf_nbr(int n);
int		ft_printf(const char *str, ...);

#endif
