/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operateur_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 13:17:02 by danglass          #+#    #+#             */
/*   Updated: 2019/03/20 14:31:12 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	ft_swap(int *pile, char letter)
{
	int swap;

	swap = pile[0];
	pile[0] = pile[1];
	pile[1] = swap;
	if (letter == 'a')
		ft_putendl("sa");
	if (letter == 'b')
		ft_putendl("sb");
	return ;
}

void	ft_swap_all(int *pile_a, int *pile_b)
{
	int swap;

	swap = pile_a[0];
	pile_a[0] = pile_a[1];
	pile_a[1] = swap;
	swap = pile_b[0];
	pile_b[0] = pile_b[1];
	pile_b[1] = swap;
	ft_putendl("ss");
	return ;
}

void	ft_push(int *pile_1, int *pile_2, int *len_1, int *len_2)
{
	int push;
	int index;

	push = pile_1[0];
	index = 0;
	while (index < *len_1)
	{
		pile_1[index] = pile_1[index + 1];
		index++;
	}
	pile_1[index] = 0;
	index = *len_2;
	while (index >= 0)
	{
		pile_2[index + 1] = pile_2[index];
		index--;
	}
	pile_2[0] = push;
	*len_1 = *len_1 - 1;
	*len_2 = *len_2 + 1;
	return ;
}

void	ft_rotate(int *pile, int len, char letter)
{
	int swap;
	int index;

	swap = pile[0];
	index = 0;
	while (index < len)
	{
		pile[index] = pile[index + 1];
		index++;
	}
	pile[len] = swap;
	if (letter == 'a')
		ft_putendl("ra");
	if (letter == 'b')
		ft_putendl("rb");
	return ;
}

void	ft_rotate_all(int *pile_1, int *pile_2, int len_1, int len_2)
{
	int swap;
	int index;

	swap = pile_1[0];
	index = 0;
	while (index < len_1)
	{
		pile_1[index] = pile_1[index + 1];
		index++;
	}
	pile_1[len_1] = swap;
	swap = pile_2[0];
	index = 0;
	while (index < len_2)
	{
		pile_2[index] = pile_2[index + 1];
		index++;
	}
	pile_2[len_2] = swap;
	ft_putendl("rr");
	return ;
}
