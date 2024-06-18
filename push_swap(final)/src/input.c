/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brsantsc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 08:46:55 by brsantsc          #+#    #+#             */
/*   Updated: 2024/06/18 08:46:58 by brsantsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/libft.h"

t_stack	*enter_input(int ac, char **av)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 0;
	while (i < ac - 1)
	{
		checks(av[i + 1], stack_a);
		stack_a = add_node(stack_a, ft_atoi(av[i + 1]));
		i++;
	}
	return (stack_a);
}

t_stack	*get_input(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = NULL;
	stack_a = enter_input(ac, av);
	return (stack_a);
}
