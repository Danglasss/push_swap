/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:41:18 by damboule          #+#    #+#             */
/*   Updated: 2018/11/20 18:42:08 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive_pos(int n)
{
	if (n / 10 > 0)
	{
		ft_recursive_pos(n /= 10);
		ft_putchar((n % 10) + '0');
	}
}

void		ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_recursive_pos(n);
	ft_putchar((n % 10) + '0');
}
