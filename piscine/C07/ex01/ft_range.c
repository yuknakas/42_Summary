/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:24:07 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/26 14:04:49 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	nb_count;
	int	*sequence;

	if (min >= max)
		return (NULL);
	nb_count = max - min;
	sequence = malloc(nb_count * sizeof(int));
	if (sequence == NULL)
		return (NULL);
	i = 0;
	while (i < nb_count)
	{
		sequence[i] = min + i;
		i++;
	}
	return (sequence);
}
