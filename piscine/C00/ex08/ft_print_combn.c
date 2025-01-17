/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 08:48:30 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/29 11:18:45 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_number(int num)
{
	char	buffer[3];
	int		i;

	i = 0;
	if (num < 10)
	{
		buffer[i++] = '0' + num;
		buffer[i] = '\0';
	}
	else
	{
		buffer[i++] = '0' + (num / 10);
		buffer[i++] = '0' + (num % 10);
		buffer[i] = '\0';
	}
	write(1, buffer, i);
}

void	generate_combinations(int start, int n, int *comb, int depth)
{
	int	i;

	if (depth == n)
	{
		i = 0;
		while (i < n)
		{
			write_number(comb[i]);
			++i;
		}
		if (comb[0] != 10 - n)
		{
			write(1, ", ", 2);
		}
		return ;
	}
	i = start;
	while (i <= 9 - n + depth + 1)
	{
		comb[depth] = i;
		generate_combinations(i + 1, n, comb, depth + 1);
		++i;
	}
}

void	ft_print_combn(int n)
{
	int	comb[10];

	if (n < 1 || n >= 10)
	{
		return ;
	}
	generate_combinations(0, n, comb, 0);
}
