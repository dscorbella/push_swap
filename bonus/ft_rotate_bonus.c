/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:27:50 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/02 13:29:17 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	ft_rotate_r(t_stack **stacka, t_stack **stackb)
{
	ft_rotate (stacka);
	ft_rotate (stackb);
}
