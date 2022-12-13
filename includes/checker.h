/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:41:44 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/03 21:12:47 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int			ft_checker( char **argv);
t_stack		*fill_a(int argc, char **argv);
long int	ft_atoi(const char *str);
char		*gnl(int fd);
int			ft_sorted(t_stack *stack);
int			checker_move(char *move, t_stack **stack_a, t_stack **stack_b);
int			do_move(char *mov, t_stack **stack_a, t_stack **stack_b);
void		ft_push(t_stack **src, t_stack **dst);
void		ft_swap(t_stack *stack);
void		ft_rotate(t_stack **stack);
void		ft_rotate_r(t_stack **stacka, t_stack **stackb);
t_stack		*go_down(t_stack *stack);
void		ft_revrot(t_stack **stack);
void		ft_revrot_r(t_stack **stacka, t_stack **stackb);
int			free_stack(t_stack **stack_a, t_stack **stack_b);

#endif
