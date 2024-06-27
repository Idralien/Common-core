/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 09:31:02 by brsantsc          #+#    #+#             */
/*   Updated: 2024/04/15 09:35:03 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	if (!del || !lst)
//		return (NULL);

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
	lst = NULL;
}
