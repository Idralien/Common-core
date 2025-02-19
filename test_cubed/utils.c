/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <brsantsc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:34:51 by brsantsc          #+#    #+#             */
/*   Updated: 2025/02/18 15:42:23 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void    error_exit(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void    fsplit(char **array)
{
    int i = 0;
    if (!array)
        return;

    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}
