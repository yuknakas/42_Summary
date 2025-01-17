/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:33:58 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/29 10:21:20 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charseq(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	countseq(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (!(is_charseq(str[i], charset)))
		{
			if (i == 0 || is_charseq(str[i - 1], charset))
				count++;
		}
		i++;
	}
	return (count);
}

char	*copy(char *str, int start, int length)
{
	char	*dest;
	int		i;

	dest = malloc(length + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (i < length)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}

char	*control(int *i, char *str, char *charset)
{
	int		start;
	int		tmp_i;
	char	*dest;

	start = *i;
	tmp_i = *i;
	while (str[tmp_i] && !is_charseq(str[tmp_i], charset))
		tmp_i++;
	dest = copy(str, start, tmp_i - start);
	*i = tmp_i;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	j = 0;
	result = malloc((countseq(str, charset) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (!is_charseq(str[i], charset))
		{
			result[j] = control(&i, str, charset);
			j++;
		}
		else
		{
			i++;
		}
	}
	result[j] = NULL;
	return (result);
}
