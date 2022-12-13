/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:06 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/02 13:22:12 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*go_second_down(t_stack *stack)
{
	t_stack	*tmp;

	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	tmp = stack;
	return (tmp);
}

void	ft_revrot(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*bfr_last;

	last = go_down(*stack);
	bfr_last = go_second_down(*stack);
	tmp = *stack;
	*stack = last;
	(*stack)->next = tmp;
	bfr_last->next = NULL;
}

void	ft_revrot_a(t_stack **stack)
{
	ft_revrot(stack);
	write (1, "rra\n", 4);
}

void	ft_revrot_b(t_stack **stack)
{
	ft_revrot(stack);
	write (1, "rrb\n", 4);
}

void	ft_revrot_r(t_stack **stacka, t_stack **stackb)
{
	ft_revrot(stacka);
	ft_revrot(stackb);
	write (1, "rrr\n", 4);
}
