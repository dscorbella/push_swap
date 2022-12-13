/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stakcs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:32:07 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/04 16:26:01 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_a(int argc, char **argv)
{
	t_stack		*stack_a;
	int			i;
	long int	num;

	i = 1;
	stack_a = NULL;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (i == 1)
			stack_a = list_new((int)num);
		else
			add_list_bot(stack_a, list_new((int)num));
		i++;
	}
	return (stack_a);
}

t_stack	*list_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
	new->index = 0;
	new->pos = 0;
	new->posba = 0;
	new->cost = 0;
	new->costba = 0;
	new->fcost = 0;
	new->next = NULL;
	return (new);
}

void	add_list_bot(t_stack *stack_a, t_stack *new)
{
	t_stack	*added;

	if (!new)
		return ;
	if (!stack_a)
	{
		added = new;
		return ;
	}
	while (stack_a && stack_a->next != NULL)
		stack_a = stack_a->next;
	added = stack_a;
	added->next = new;
}

int	ft_size(t_stack *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

void	ft_index(t_stack *stack, int size)
{
	t_stack	*tmp;
	t_stack	*tmin;
	int		index;
	int		valuemin;

	index = 1;
	tmin = NULL;
	while (index <= size)
	{
		tmp = stack;
		valuemin = INT_MAX;
		while (tmp)
		{
			if (tmp->value <= valuemin && tmp->index == 0)
			{
				valuemin = tmp->value;
				tmin = tmp;
			}
			tmp = tmp->next;
		}
		if (tmin != NULL)
			tmin->index = index;
		index++;
	}
}
