/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:50:28 by quvan-de          #+#    #+#             */
/*   Updated: 2025/03/06 16:50:32 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtok(char *str, char separrator)
{
	static char	*dup = NULL;
	char		*ptr;
	int			i;

	i = 0;
	ptr = NULL;
	if (str != NULL)
		dup = ft_strdup(str);
	while (*dup != '\0')
	{
		if (i == 0 && *dup != separrator)
		{
			i = 1;
			ptr = dup;
		}
		else if (i == 1 && *dup == separrator)
		{
			*dup = '\0';
			dup += 1;
			break ;
		}
		dup++;
	}
	return (ptr);
}
