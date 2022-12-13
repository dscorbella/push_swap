/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:27:50 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/02 13:21:56 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*go_down(t_stack *stack)
{
	t_stack	*tmp;

	while (stack && stack->next != NULL)
		stack = stack->next;
	tmp = stack;
	return (tmp);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*new;

	if (stack == NULL || go_down(*stack) == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	new = go_down(*stack);
	tmp->next = NULL;
	new->next = tmp;
}

void	ft_rotate_a(t_stack **stack)
{
	ft_rotate (stack);
	write (1, "ra\n", 3);
}

void	ft_rotate_b(t_stack **stack)
{
	ft_rotate (stack);
	write (1, "rb\n", 3);
}

void	ft_rotate_r(t_stack **stacka, t_stack **stackb)
{
	ft_rotate (stacka);
	ft_rotate (stackb);
	write (1, "rr\n", 3);
}
