/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 08:42:31 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/26 08:47:50 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid(int *queens, int row, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (queens[i] == row || queens[i] - i == row - col)
			return (0);
		if (queens[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int *queens, int col, int *count)
{
	int		i;
	char	buffer[11];

	i = 0;
	if (col == 10)
	{
		while (i < 10)
		{
			buffer[i] = queens[i] + '0';
			i++;
		}
		buffer[10] = '\n';
		write(1, buffer, 11);
		(*count)++;
		return ;
	}
	while (i < 10)
	{
		if (is_valid(queens, i, col))
		{
			queens[col] = i;
			solve(queens, col + 1, count);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	queens[10];
	int	count;

	count = 0;
	solve(queens, 0, &count);
	return (count);
}
