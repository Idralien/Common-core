/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:35:47 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/29 09:35:49 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_hex(unsigned int value, int ascii);
int		ft_print_nbr(int n);
int		ft_print_ptr(unsigned long value, int ascii);
int		ft_print_str(char *str);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_char(int c);

#endif
