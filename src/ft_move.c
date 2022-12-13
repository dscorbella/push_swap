/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:04:12 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/02 13:23:27 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rmove(t_stack **stack_a, t_stack **stack_b, int costa, int costb)
{
	int	i;

	i = 0;
	if (costa > 0 && costb > 0)
	{
		while ((costa + i) > 0 && (costb + i) > 0)
		{
			ft_rotate_r(stack_a, stack_b);
			i--;
		}
	}
	else
	{
		while ((costa + i) < 0 && (costb + i) < 0)
		{
			ft_revrot_r(stack_a, stack_b);
			i++;
		}
	}
	return (i);
}

void	ft_move(t_stack **stack_a, t_stack **stack_b, int costa, int costb)
{
	int	r;
	int	tmp;

	r = 0;
	if (costa * costb > 0)
		r = ft_rmove(stack_a, stack_b, costa, costb);
	costa = costa + r;
	costb = costb + r;
	tmp = costa;
	while (--tmp >= 0)
		ft_rotate_a(stack_a);
	while (++costa <= 0)
		ft_revrot_a(stack_a);
	tmp = costb;
	while (--tmp >= 0)
		ft_rotate_b(stack_b);
	while (++costb <= 0)
		ft_revrot_b(stack_b);
	ft_push_a(stack_b, stack_a);
}

void	cheap_move(t_stack **stack_a, t_stack **stack_b)
{
	int		cheap;
	int		cost_a;
	int		cost_b;
	t_stack	*tmp;

	tmp = *stack_b;
	cheap = INT_MAX;
	cost_a = 0;
	cost_b = 0;
	while (tmp)
	{
		if (tmp->fcost < cheap)
		{
			cheap = tmp->fcost;
			cost_b = tmp->cost;
			cost_a = tmp->costba;
		}
		tmp = tmp->next;
	}
	ft_move(stack_a, stack_b, cost_a, cost_b);
}

void	finish_rotate(t_stack **stack, int size)
{
	t_stack	*tmp;
	int		lowpos;
	int		lowest;

	tmp = *stack;
	lowest = INT_MAX;
	lowpos = 0;
	position(*stack, NULL);
	while (tmp)
	{
		if (tmp->index < lowest)
		{
			lowest = tmp->index;
			lowpos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (lowpos <= ((size / 2) + 1))
	{
		while (--lowpos)
			ft_rotate_a(stack);
	}
	else
		while (lowpos++ <= size)
			ft_revrot_a(stack);
}
