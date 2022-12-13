/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:29:06 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/04 15:36:01 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_revrot_r(t_stack **stacka, t_stack **stackb)
{
	ft_revrot(stacka);
	ft_revrot(stackb);
}
