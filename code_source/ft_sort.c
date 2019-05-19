/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 14:23:11 by damboule          #+#    #+#             */
/*   Updated: 2019/05/01 15:52:05 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	backreverse(int reverse, int *list, int len, int a)
{
	int index;

	index = 0;
	if (a <= 2)
		return ;
	while (index < reverse)
	{
		ft_reverse(list, len, 'a');
		index++;
	}
}

void	ft_pushona(int *list_a, int *list_b, int *len, int count)
{
	int index;

	index = 0;
	while (index < count)
	{
		ft_push(list_b, list_a, &len[1], &len[0]);
		ft_putendl("pa");
		index++;
	}
}

int		ft_partionement(int *list_a, int *list_b, int *len, int *med)
{
	int push_count;
	int index;
	int reverse;
	int iter;

	index = -1;
	push_count = 0;
	reverse = 0;
	iter = len[0] + 1;
	while (++index < iter && ft_countlen_a(list_a, iter, index, med[0]))
	{
		if (list_a[0] <= med[0])
		{
			ft_push(list_a, list_b, &len[0], &len[1]);
			ft_putendl("pb");
			push_count++;
		}
		else
		{
			ft_rotate(list_a, len[0], 'a');
			reverse++;
		}
	}
	backreverse(reverse, list_a, len[0], med[1]);
	return (push_count);
}

void	ft_quicksort(int *list_a, int *list_b, int *len, int *med)
{
	int count;

	if (len[0] + 1 <= med[1])
	{
		ft_sortlist(list_a, list_b, len);
		return ;
	}
	med[0] = ft_mediane(list_a, (len[0] - (med[1] - 2)) + 1, 2);
	count = ft_partionement(list_a, list_b, len, med);
	ft_quicksort(list_a, list_b, len, med);
	ft_pushona(list_a, list_b, len, count);
	med[1] += 2;
	ft_quicksort(list_a, list_b, len, med);
}

void	main_quicksort(int *list_a, int *list_b, int *len)
{
	int med[3];

	med[1] = 2;
	ft_quicksort(list_a, list_b, len, med);
}
