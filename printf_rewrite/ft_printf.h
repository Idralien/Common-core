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
# include "./libft/libft.h"

int			ft_hexlen(unsigned int nbr);
void		ft_puthex(unsigned int n, const char format);
int			ft_printhex(unsigned long nbr, const char format);
void		ft_format(va_list args, const char *format, size_t *counter);
void		ft_putunsigned(unsigned int n);
void		ft_printf_char(int c, size_t *counter);
void		ft_printf_str(char *str, size_t *counter);
int			ft_printf_ptr(unsigned int value, int asc);
void		ft_printf_nbr(int nbr, size_t *counter);
int			ft_printf(const char *str, ...);
char		*make_str(unsigned int value, int *len);

#endif
