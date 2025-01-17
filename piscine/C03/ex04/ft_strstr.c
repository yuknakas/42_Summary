/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 12:36:21 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/22 12:37:49 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*temp;

	if (to_find[0] == '\0')
		return (str);
	while (*str)
	{
		i = 0;
		temp = str;
		while (str[i] == to_find[i] && to_find[i] != '\0')
		{
			i++;
		}
		if (to_find[i] == '\0')
			return (temp);
		str++;
	}
	return (NULL);
}
