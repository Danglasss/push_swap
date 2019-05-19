/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:47:34 by damboule          #+#    #+#             */
/*   Updated: 2018/11/20 18:41:48 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive_ps(int n, int fd)
{
	if (n / 10 > 0)
	{
		ft_recursive_ps(n /= 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	if (fd == -1 || fd == 0)
		return ;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	ft_recursive_ps(n, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
