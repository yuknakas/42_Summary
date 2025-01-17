/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 12:11:42 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/14 12:16:05 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	ascii_value;

	ascii_value = 122;
	while (ascii_value >= 97)
	{
		write(1, &ascii_value, 1);
		ascii_value--;
	}
}
