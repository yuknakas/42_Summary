/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 16:05:01 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/26 09:26:53 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	top;
	long	root;
	long	bottom;

	top = nb;
	bottom = 0;
	while (bottom <= top)
	{
		root = (top + bottom) / 2;
		if (nb == root * root)
			return (root + 1);
		else if (nb < root * root)
			top = root -1;
		else
			bottom = root + 1;
	}
	return (root + 1);
}

int	ft_is_prime(int nb)
{
	int	divider;
	int	limit;

	if (nb <= 1)
		return (0);
	if (nb != 2 && nb % 2 == 0)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	limit = ft_sqrt(nb);
	divider = 3;
	while (divider <= limit)
	{
		if (nb % divider == 0)
			return (0);
		divider += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	if (nb != 1 && nb % 2 == 1)
		return (ft_find_next_prime(nb + 2));
	else
		return (ft_find_next_prime(nb + 1));
}
