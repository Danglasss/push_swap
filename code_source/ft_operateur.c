/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operateur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:26:12 by danglass          #+#    #+#             */
/*   Updated: 2019/03/22 14:02:50 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	ft_reverse(int *pile, int len, char letter)
{
	int swap;
	int count;

	count = 0;
	swap = pile[len];
	while (len > 0)
	{
		pile[len] = pile[len - 1];
		len--;
	}
	pile[0] = swap;
	if (letter == 'a')
		ft_putendl("rra");
	if (letter == 'b')
		ft_putendl("rrb");
	return ;
}

void	ft_reverse_all(int *pile_1, int *pile_2, int len_1, int len_2)
{
	int swap;
	int count;

	count = 0;
	swap = pile_1[len_1];
	while (len_1 > 0)
	{
		pile_1[len_1] = pile_1[len_1 - 1];
		len_1--;
	}
	pile_1[0] = swap;
	count = 0;
	swap = pile_2[len_2];
	while (len_2 > 0)
	{
		pile_2[len_2] = pile_2[len_2 - 1];
		len_2--;
	}
	pile_2[0] = swap;
	ft_putendl("rrr");
	return ;
}
