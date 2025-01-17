/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:32:17 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/28 16:42:46 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	index_length(char *baseletters)
{
	int	counter;

	counter = 0;
	while (baseletters[counter] != '\0')
		counter++;
	return (counter);
}

int	converter(char *str, char *base)
{
	unsigned int	ans;
	unsigned int	i;
	unsigned int	baselength;
	int				flag;

	baselength = index_length(base);
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

int	ft_atoi_base(char *str, char *base)
{
	unsigned int	result;
	int				sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || ('\t' <= *str && *str <= '\r'))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = converter(str, base);
	return (sign * result);
}
