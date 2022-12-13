/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:43:20 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/05 10:37:44 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*list_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = value;
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
