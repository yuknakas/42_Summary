/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 11:45:59 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/29 12:56:02 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

int		valid_base(char *basevalue);
long	dec_converter(char *str, char *base, unsigned int baselength);
long	ft_atoi_base(char *nbr, char *base_from);
char	*convert_to(long dec_value, char *base_to, int length, int digits);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int		digit_count(long dec_value, int baselength_to);

int	valid_base(char *basevalue)
{
	int	i;
	int	j;

	if (basevalue == NULL || basevalue[0] == '\0' || basevalue[1] == '\0')
		return (0);
	i = 0;
	while (basevalue[i] != '\0')
	{
		if (basevalue[i] == '+' || basevalue[i] == '-')
			return (0);
		if (32 >= basevalue[i] || basevalue[i] >= 127)
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

long	dec_converter(char *str, char *base, unsigned int baselength)
{
	long			ans;
	unsigned int	i;
	int				flag;

	ans = 0;
	while (*str)
	{
		i = 0;
		flag = 0;
		while (base[i] != '\0')
		{
			if (*str == base[i])
			{
				flag = 1;
				ans = ans * baselength + i;
			}
			i++;
		}
		if (flag == 0)
			return (ans);
		str++;
	}
	return (ans);
}

long	ft_atoi_base(char *nbr, char *base_from)
{
	long			result;
	long			sign;
	unsigned int	baselength;

	baselength = 0;
	while (base_from[baselength] != '\0')
		baselength++;
	result = 0;
	sign = 1;
	while (*nbr == ' ' || ('\t' <= *nbr && *nbr <= '\r'))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	result = dec_converter(nbr, base_from, baselength);
	return (sign * result);
}

char	*convert_to(long dec_value, char *base_to, int length, int digits)
{
	char	*answer;
	int		i;
	int		flag;

	answer = malloc((digits + 1) * sizeof(char));
	if (answer == NULL)
		return (NULL);
	flag = 0;
	if (dec_value < 0)
	{
		dec_value = -dec_value;
		answer[0] = '-';
		flag = 1;
	}
	i = digits - 1;
	while (i > 0)
	{
		answer[i] = base_to[dec_value % length];
		i--;
		dec_value /= length;
	}
	if (flag == 0)
		answer[i] = base_to[dec_value % length];
	answer[digits] = '\0';
	return (answer);
}

int	digit_count(long dec_value, int baselength_to)
{
	int	counter;

	counter = 1;
	if (dec_value < 0)
	{
		counter++;
		dec_value = -dec_value;
	}
	while (dec_value >= baselength_to)
	{
		counter++;
		dec_value /= baselength_to;
	}
	return (counter);
}
