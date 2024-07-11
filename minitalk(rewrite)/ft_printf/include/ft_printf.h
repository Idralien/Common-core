/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 09:35:47 by brsantsc          #+#    #+#             */
/*   Updated: 2024/07/11 14:43:19 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void		ft_hex(unsigned int x, int *len, char hex);
void		ft_nbr(int nbr, int *len);
void		ft_ptr(size_t ptr, int *len);
void		ft_print_string(char *str, int *len);
void		ft_unsigned(unsigned int i, int *len);
void		ft_print_char(char words, int *len);

size_t	ft_strlen(const char *str);
int			ft_atoi(const char *str);

int		ft_printf(const char *str, ...);

void	bits_handler(int bits);
void	send_signal(int server_pid, char *str, size_t len);


typedef struct s_buffer
{
	unsigned char	c;
	int		i;
}		t_buffer;

#endif
