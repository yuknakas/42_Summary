/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 09:56:59 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/21 15:56:48 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	let_or_nb(char c)
{
	if ('a' <= c && c <= 'z')
		return (-1);
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('0' <= c && c <= '9')
		return (5);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (let_or_nb(str[i]) != 0)
		{
			if (let_or_nb(str[i]) == -1)
				str[i] -= 32;
			i++;
			while (let_or_nb(str[i]) != 0)
			{
				if (let_or_nb(str[i]) == 1)
					str[i] += 32;
				i++;
			}
		}
		i++;
	}
	return (str);
}
