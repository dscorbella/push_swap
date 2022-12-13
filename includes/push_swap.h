/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:22:10 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/04 15:50:52 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				posba;
	int				cost;
	int				costba;
	int				fcost;
	struct s_stack	*next;
}	t_stack;

long int	ft_atoi(const char *str);
int			ft_abs(int n);
t_stack		*fill_a(int argc, char **argv);
t_stack		*list_new(int value);
void		add_list_bot(t_stack *stack_a, t_stack *new);
int			ft_size(t_stack *stack);
void		ft_index(t_stack *stack, int size);
int			ft_checker( char **argv);
void		ft_swap_a(t_stack *stack);
void		ft_swap_b(t_stack *stack);
t_stack		*go_down(t_stack *stack);
void		ft_rotate_a(t_stack **stack);
void		ft_rotate_b(t_stack **stack);
void		ft_rotate_r(t_stack **stacka, t_stack **stackb);
t_stack		*go_second_down(t_stack *stack);
void		ft_revrot_a(t_stack **stack);
void		ft_revrot_b(t_stack **stack);
void		ft_revrot_r(t_stack **stacka, t_stack **stackb);
void		ft_push_a(t_stack **stack_b, t_stack **stack_a);
void		ft_push_b(t_stack **stack_a, t_stack **stack_b);
void		ft_play(t_stack **stack_a, t_stack **stack_b, int size);
int			ft_sorted(t_stack *stack);
void		position(t_stack *stack_a, t_stack *stack_b);
void		cost(t_stack *stack_a, t_stack *stack_b);
void		cheap_move(t_stack **stack_a, t_stack **stack_b);
void		ft_move(t_stack **stack_a, t_stack **stack_b, int costa, int costb);
void		finish_rotate(t_stack **stack, int size);
void		free_stack(t_stack **stack);

#endif
