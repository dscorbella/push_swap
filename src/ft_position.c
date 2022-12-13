/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:20:13 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/02 13:22:55 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	positionb(t_stack *stack_a, t_stack *stack_b, int poslow)
{
	t_stack	*tmp;
	int		j;
	int		lowest;

	j = 1;
	tmp = stack_a;
	while (stack_b)
	{
		lowest = INT_MAX;
		while (stack_a)
		{
			if ((stack_b->index < stack_a->index) && (stack_a->index < lowest))
			{
				stack_b->posba = stack_a->pos;
				lowest = stack_a->index;
			}
			stack_a = stack_a->next;
		}
		stack_a = tmp;
		if (lowest == INT_MAX)
			stack_b->posba = poslow;
		stack_b->pos = j;
		j++;
		stack_b = stack_b->next;
	}
}

void	position(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		sizea;
	int		lowest;
	int		poslow;
	int		i;

	i = 1;
	sizea = ft_size(stack_a);
	tmp = stack_a;
	lowest = INT_MAX;
	poslow = 0;
	while (i <= sizea)
	{
		tmp->pos = i;
		if (tmp->index < lowest)
		{
			lowest = tmp->index;
			poslow = tmp->pos;
		}
		tmp = tmp->next;
		i++;
	}
	tmp = stack_b;
	positionb(stack_a, stack_b, poslow);
}

void	calc_cost(t_stack *stack, int size)
{
	while (stack)
	{
		if (stack->pos <= (size / 2) + 1)
			stack->cost = stack->pos - 1;
		else
			stack->cost = stack->pos - size - 1;
		stack = stack->next;
	}
}

void	cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp;
	int		sizea;
	int		sizeb;

	tmp = stack_b;
	sizea = ft_size(stack_a);
	sizeb = ft_size(stack_b);
	calc_cost(stack_a, sizea);
	calc_cost(stack_b, sizeb);
	while (stack_b)
	{
		if (stack_b->posba <= (sizea / 2) + 1)
			stack_b->costba = stack_b->posba - 1;
		else
			stack_b->costba = stack_b->posba - sizea - 1;
		if (stack_b->cost * stack_b->costba < 0)
			stack_b->fcost = ft_abs(stack_b->cost) + ft_abs(stack_b->costba);
		else if (ft_abs(stack_b->cost) >= ft_abs(stack_b->costba))
			stack_b->fcost = ft_abs(stack_b->cost);
		else
			stack_b->fcost = ft_abs(stack_b->costba);
		stack_b = stack_b->next;
	}
}

int	ft_abs(int n)
{
	if (n < 0 && n != INT_MIN)
		return (-n);
	return (n);
}
