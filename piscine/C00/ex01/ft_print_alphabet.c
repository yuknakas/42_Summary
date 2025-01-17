/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:29:35 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/14 12:16:06 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	ascii_value;

	ascii_value = 97;
	while (ascii_value <= 122)
	{
		write(1, &ascii_value, 1);
		ascii_value++;
	}
}
