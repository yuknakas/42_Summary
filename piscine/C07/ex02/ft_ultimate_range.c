/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:08:38 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/26 14:42:45 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	nb_count;
	int	*sequence;

	*range = NULL;
	if (min >= max)
	{
		return (0);
	}
	nb_count = max - min;
	sequence = malloc(nb_count * sizeof(int));
	if (sequence == NULL)
	{
		return (-1);
	}
	i = 0;
	while (i < nb_count)
	{
		sequence[i] = min + i;
		i++;
	}
	*range = sequence;
	return (nb_count);
}
