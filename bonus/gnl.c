/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davsanch <davsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:41:15 by davsanch          #+#    #+#             */
/*   Updated: 2022/11/02 13:30:11 by davsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*gnl(int fd)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = malloc(5);
	buffer[0] = '\0';
	if (fd < 0)
		return (NULL);
	while (read(fd, &buffer[i], 1) == 1)
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (!buffer[0])
	{
		free (buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
