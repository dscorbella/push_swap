/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:24:06 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/02 13:23:43 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	numeric(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == 32 || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '+' || arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	repeat(int n, int i, char **argv)
{
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == n)
			return (0);
		i++;
	}
	return (1);
}

int	ft_checker( char **argv)
{
	int	i;
	int	check;

	i = 1;
	check = 1;
	while (argv[i])
	{
		if (!numeric(argv[i]))
			return (0);
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (0);
		if (!repeat(ft_atoi(argv[i]), (i + 1), argv))
			return (0);
		i++;
	}
	return (1);
}

long int	ft_atoi(const char *str)
{	
	int			i;
	long int	sig;
	long int	result;

	i = 0;
	result = 0;
	sig = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -sig;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sig);
}
