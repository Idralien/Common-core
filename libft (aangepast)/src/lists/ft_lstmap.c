/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:29:22 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/03 16:29:25 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*saved_lst;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew((*f)(lst->content));
	if (!new_lst)
		return (NULL);
	saved_lst = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew((*f)(lst->content));
		if (!new_lst->next)
		{
			ft_lstclear(&saved_lst, del);
			return (NULL);
		}
		new_lst = new_lst->next;
		lst = lst->next;
	}
	new_lst->next = NULL;
	return (saved_lst);
}
