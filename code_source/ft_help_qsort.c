/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_qsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 23:07:25 by damboule          #+#    #+#             */
/*   Updated: 2019/04/29 16:12:44 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int			ft_countlen(int *list_b, int len, int index, int pivot_mix)
{
	int len_b;
	int temp;

	temp = 0;
	len_b = len - index;
	while (temp < len_b + 1)
	{
		if (list_b[temp] > pivot_mix)
			return (1);
		temp++;
	}
	return (0);
}

void		ft_make_swap(int *list_a, int *list_b, int *len)
{
	if (list_a[0] > list_a[1] && list_b[0] < list_b[1]
	&& len[1] > 0 && len[0] > 0)
		ft_swap_all(list_a, list_b);
	else if (list_b[0] < list_b[1] && len[1] > 0)
		ft_swap(list_b, 'b');
	else if (list_a[0] > list_a[1] && len[0] > 0)
		ft_swap(list_a, 'a');
	return ;
}

int			ft_find_num(int *list, int index, int num)
{
	int temp;

	temp = 0;
	while (temp < index)
	{
		if (list[temp] > num)
			return (1);
		temp++;
	}
	return (0);
}

int			ft_len_sort(int *list, int len, int lin, int count)
{
	int index;

	index = len;
	while (index > 0 && ++count > -10)
	{
		if (list[index] > list[index - 1])
		{
			if (ft_find_num(list, index, list[index]))
			{
				if (lin <= count)
					return (count - 1);
				return (lin);
			}
		}
		else if (list[index] < list[index - 1])
		{
			if (lin <= count)
				return (count - 1);
			return (lin);
		}
		index--;
	}
	if (lin <= count)
		return (count - 1);
	return (lin);
}

int			ft_countlen_a(int *list_a, int len, int index, int pivot_mix)
{
	int len_b;
	int temp;

	temp = 0;
	len_b = len - index;
	while (temp < len_b)
	{
		if (list_a[temp] <= pivot_mix)
			return (1);
		temp++;
	}
	return (0);
}
