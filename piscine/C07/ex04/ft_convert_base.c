/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 10:19:33 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/29 14:09:07 by yuknakas         ###   ########.fr       */
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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long			dec_value;
	unsigned int	baselength_to;
	int				digits;
	char			*answer;

	if (valid_base(base_from) == 0 || valid_base(base_to) == 0)
		return (NULL);
	dec_value = ft_atoi_base(nbr, base_from);
	baselength_to = 0;
	while (base_to[baselength_to] != '\0')
		baselength_to++;
	digits = digit_count(dec_value, baselength_to);
	answer = malloc((digits + 1) * sizeof(char));
	if (answer == NULL)
		return (NULL);
	answer = convert_to(dec_value, base_to, baselength_to, digits);
	return (answer);
}
