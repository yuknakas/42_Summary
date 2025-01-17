/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 13:48:34 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/28 14:39:37 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	str_len(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
		counter ++;
	return (counter);
}

char	*str_dup(char *str)
{
	char	*dup;
	int		len;
	int		i;

	len = str_len(str);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	i = -1;
	tab = malloc((ac + 1) * sizeof(t_stock_str));
	if (tab == NULL)
		return (NULL);
	while (i++ < ac - 1)
	{
		tab[i].size = str_len(av[i]);
		tab[i].str = av[i];
		tab[i].copy = str_dup(av[i]);
		if (tab[i].copy == NULL)
		{
			while (i >= 0)
			{
				free(tab[i].copy);
				i--;
			}
			free(tab);
			return (NULL);
		}
	}
	tab[i].str = NULL;
	return (tab);
}
