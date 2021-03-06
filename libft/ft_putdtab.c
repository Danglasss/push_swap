/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdtab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:49:09 by damboule          #+#    #+#             */
/*   Updated: 2018/11/13 15:38:08 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdtab(char **tab)
{
	int	a;

	a = 0;
	while (tab[a] != 0)
	{
		ft_putstr(tab[a]);
		ft_putchar('\n');
		a++;
	}
}
