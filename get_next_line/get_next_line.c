/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 11:14:25 by brsantsc          #+#    #+#             */
/*   Updated: 2024/05/08 14:02:55 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	print_newline(char *buffer)
{
	while (*buffer && *buffer != '\0')
	{
		if(*buffer == '\n')
			*buffer = '\\';
		printf("%c", *buffer);
		buffer++;
	}
}

static char	*read_file(int fd)
{
	int	bytes_read;
	char	*buffer;
	static int	count = 1;

	printf("ft_calloc#[%d]---", count++);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if(!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	if(bytes_read <= 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = read_file(fd);
	return (buffer);
}

int	main(void)
{
}
