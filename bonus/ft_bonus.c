/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:35:33 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/03 21:12:56 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (!ft_checker(argv))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	stack_a = fill_a(argc, argv);
	while (checker_move(gnl(0), &stack_a, &stack_b))
		continue ;
	if (!ft_sorted(stack_a) || stack_b)
	{
		write(2, "KO\n", 3);
		return (free_stack(&stack_a, &stack_b));
	}
	else if (stack_a)
	{
		free_stack(&stack_a, &stack_b);
		return (write(2, "OK\n", 3));
	}
	return (0);
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

int	checker_move(char *move, t_stack **stack_a, t_stack **stack_b)
{
	if (!move)
		return (0);
	if (!do_move(move, stack_a, stack_b))
	{	
		free (move);
		write(2, "Error\n", 6);
		return (free_stack(stack_a, stack_b));
	}
	free (move);
	return (1);
}	

int	do_move(char *mov, t_stack **stack_a, t_stack **stack_b)
{
	if (mov[0] == 'p' && mov[1] == 'a' && mov[2] == '\n')
		ft_push(stack_b, stack_a);
	else if (mov[0] == 'p' && mov[1] == 'b' && mov[2] == '\n')
		ft_push(stack_a, stack_b);
	else if (mov[0] == 's' && mov[1] == 'a' && mov[2] == '\n')
		ft_swap(*stack_a);
	else if (mov[0] == 's' && mov[1] == 'b' && mov[2] == '\n')
		ft_swap(*stack_b);
	else if (mov[0] == 'r' && mov[1] == 'a' && mov[2] == '\n')
		ft_rotate(stack_a);
	else if (mov[0] == 'r' && mov[1] == 'b' && mov[2] == '\n')
		ft_rotate(stack_b);
	else if (mov[0] == 'r' && mov[1] == 'r' && mov[2] == '\n')
		ft_rotate_r(stack_a, stack_b);
	else if (mov[0] == 'r' && mov[1] == 'r' && mov[2] == 'a' && mov[3] == '\n')
		ft_revrot(stack_a);
	else if (mov[0] == 'r' && mov[1] == 'r' && mov[2] == 'b' && mov[3] == '\n')
		ft_revrot(stack_b);
	else if (mov[0] == 'r' && mov[1] == 'r' && mov[2] == 'r' && mov[3] == '\n')
		ft_revrot_r(stack_a, stack_b);
	else
		return (0);
	return (1);
}

int	free_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	while (*stack_a)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	*stack_a = NULL;
	while (*stack_b)
	{
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
	*stack_b = NULL;
	return (0);
}
