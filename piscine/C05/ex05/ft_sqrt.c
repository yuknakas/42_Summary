/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 15:46:57 by yuknakas          #+#    #+#             */
/*   Updated: 2024/08/24 10:56:38 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	top;
	long	root;
	long	bottom;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	top = nb;
	bottom = 0;
	while (bottom <= top)
	{
		root = (top + bottom) / 2;
		if (nb == root * root)
			return (root);
		else if (nb < root * root)
			top = root -1;
		else
			bottom = root + 1;
	}
	return (0);
}
