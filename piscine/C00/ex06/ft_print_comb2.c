/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:38:27 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/29 08:48:00 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int i)
{
	char	c;

	c = i + '0';
	write(1, &c, 1);
	return ;
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = i + 1;
		while (j < 100)
		{
			print(i / 10);
			print(i % 10);
			write(1, " ", 1);
			print(j / 10);
			print(j % 10);
			if (i != 98 || j != 99)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
	return ;
}

// int main()
// {
// 	ft_print_comb2();
// 	return 0;
// }
