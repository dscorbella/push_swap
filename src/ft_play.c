/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:35:11 by davsanch          #+#    #+#             */
/*   Updated: 2022/12/13 11:37:20 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if ((first > second) && (first > third))
		ft_rotate_a(stack);
	if ((first < second) && (second > third))
		ft_revrot_a(stack);
	if ((*stack)->value > (*stack)->next->value)
		ft_swap_a(*stack);
}

void	chunk(t_stack **stack_a, t_stack **stack_b, int size, int bestchunk)
{
	int	i;
	int	chunk;
	int	count;

	i = 0;
	chunk = size / bestchunk;
	count = 1;
	while ((i < chunk) && (count * chunk < size - bestchunk))
	{
		if ((*stack_a)->index <= (count * chunk))
		{
			ft_push_b(stack_a, stack_b);
			i++;
			if (i == chunk)
			{
				i = 0;
				count++;
			}
		}
		else
			ft_rotate_a(stack_a);
	}
}

void	push_less_3(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	bestchunk;

	i = 0;
	if (size < 90)
		bestchunk = 1;
	else if (size < 200)
		bestchunk = 2;
	else if (size < 400)
		bestchunk = 3;
	else if (size < 1000)
		bestchunk = 4;
	else
		bestchunk = 5;
	chunk(stack_a, stack_b, size, bestchunk);
	size = ft_size(*stack_a);
	while ((size - i) > 3)
	{
		ft_push_b(stack_a, stack_b);
		i++;
	}
}

void	ft_big_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	push_less_3(stack_a, stack_b, size);
	ft_sort_3(stack_a);
	while (*stack_b)
	{
		position(*stack_a, *stack_b);
		cost(*stack_a, *stack_b);
		cheap_move(stack_a, stack_b);
	}
	if (!ft_sorted(*stack_a))
		finish_rotate(stack_a, size);
}

void	ft_play(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (ft_sorted(*stack_a))
		return ;
	if (size <= 2)
	{
		if ((*stack_a)->next && ((*stack_a)->value > (*stack_a)->next->value))
			ft_swap_a(*stack_a);
		return ;
	}
	if (size == 3)
	{
		ft_sort_3(stack_a);
		return ;
	}
	else
		ft_big_sort(stack_a, stack_b, size);
}
