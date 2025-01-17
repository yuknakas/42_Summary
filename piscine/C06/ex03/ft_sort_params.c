/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:32:07 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/24 12:55:58 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	compare_args(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char) *s2);
}

void	sort_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (compare_args(argv[i], argv[j]) > 0)
			{
				swap(&argv[i], &argv[j]);
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	length;

	sort_args(argc, argv);
	i = 1;
	while (i < argc)
	{
		length = 0;
		while (argv[i][length] != '\0')
		{
			write(1, &argv[i][length], 1);
			length++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
