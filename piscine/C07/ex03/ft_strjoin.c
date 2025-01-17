/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:55:11 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/28 10:03:04 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_count(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i] != '\0')
		{
			i++;
			len++;
		}
		i = 0;
		while (j < size - 1 && sep[i] != '\0')
		{
			i++;
			len++;
		}
		j++;
	}
	return (len);
}

void	ft_answer(char *answer, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i] != '\0')
		{
			answer[len++] = strs[j][i++];
		}
		if (j < size -1)
		{
			i = 0;
			while (sep[i] != '\0')
			{
			answer [len++] = sep [i++];
			}
		}
		j++;
	}
	answer[len] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*answer;
	int		len;

	len = ft_count(size, strs, sep);
	answer = malloc((len + 1) * sizeof(char));
	if (answer == NULL)
		return (NULL);
	ft_answer(answer, size, strs, sep);
	if (size < 0)
	{
		answer [0] = '\0';
	}
	return (answer);
}
