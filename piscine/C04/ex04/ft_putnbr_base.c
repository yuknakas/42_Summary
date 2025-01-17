/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:25:54 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/28 16:38:59 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	valid_base(char *basevalue)
{
	int	i;
	int	j;

	if (basevalue[0] == '\0' || basevalue[1] == '\0')
		return (0);
	i = 0;
	while (basevalue[i] != '\0')
	{
		if (basevalue[i] == '+' || basevalue[i] == '-')
			return (0);
		if (basevalue[i] < 32 || 127 <= basevalue[i])
			return (0);
		j = i + 1;
		while (basevalue[j] != '\0')
		{
			if (basevalue[i] == basevalue[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	index_maker(long lnbr, char *base, int *x)
{
	int		digits;
	int		index_length;

	index_length = 0;
	digits = 1;
	while (base[index_length] != '\0')
		index_length++;
	*x = index_length;
	while (lnbr >= (long)index_length)
	{
		digits++;
		lnbr /= index_length;
	}
	return (digits);
}

void	converter(char *answer, long lnbr, char *base)
{
	int		index_length;
	int		digit;
	int		i;
	int		j;
	char	result[100];

	index_length = 0;
	digit = index_maker(lnbr, base, &index_length);
	result[digit] = '\0';
	i = digit - 1;
	while (i >= 0)
	{
		result[i] = base[lnbr % index_length];
		lnbr /= index_length;
		i--;
	}
	j = 0;
	while (result[j] != '\0')
	{
		answer[j] = result[j];
		j++;
	}
	answer[j] = '\0';
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	result[50];
	long	lnbr;
	int		i;

	if (!valid_base(base))
		return ;
	lnbr = (long)nbr;
	if (lnbr < 0)
	{
		write(1, "-", 1);
		lnbr = -lnbr;
	}
	converter(result, lnbr, base);
	i = 0;
	while (result[i] != '\0')
	{
		write(1, &result[i], 1);
		i++;
	}
}
