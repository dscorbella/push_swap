/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:35:21 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/02 13:24:02 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	if (!ft_checker(argv))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	stack_b = NULL;
	stack_a = fill_a(argc, argv);
	size = ft_size(stack_a);
	ft_index(stack_a, size);
	ft_play(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	ft_sorted(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		if (stack->next && (stack->value > stack->next->value))
			return (0);
		stack = stack->next;
	}
	return (1);
}
