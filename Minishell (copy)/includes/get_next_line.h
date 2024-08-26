/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:38:01 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/11 12:38:25 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_left_read(int fd, char *str);
char	*fetch_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	*ft_strjoin_gnl(char *left_str, char *buff);
char	*ft_strchr_gnl(char *str, int c);
size_t	ft_strlen_gnl(char *str);

#endif
