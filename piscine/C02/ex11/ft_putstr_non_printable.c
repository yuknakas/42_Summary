/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:53:05 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/22 10:38:08 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			*hexadecimal;
	int				i;
	unsigned char	c;

	hexadecimal = "0123456789abcdef";
	i = 0;
	while (str[i] != '\0')
	{
		c = (unsigned char)str[i];
		if ((str[i] >= 32 && str[i] <= 126))
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			write(1, &hexadecimal[c / 16], 1);
			write(1, &hexadecimal[c % 16], 1);
		}
		i++;
	}
}
