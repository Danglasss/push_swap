/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 13:06:27 by damboule          #+#    #+#             */
/*   Updated: 2019/04/25 14:22:01 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_long(int *list, int len, int pivot_mix)
{
	int a;

	a = 0;
	while (a <= len)
	{
		if (list[a] <= pivot_mix)
			return (1);
		a++;
	}
	return (0);
}

void	ft_sort_list_0(int *list_a, int *list_b, int *len, int *lin)
{
	int pivot_mix;
	int	index;
	int count;

	pivot_mix = ft_mediane(list_a, lin[0], 2);
	index = 0;
	count = 0;
	while (index <= lin[0] + 1)
	{
		if (list_a[0] <= pivot_mix)
		{
			ft_push(list_a, list_b, &len[0], &len[1]);
			ft_putendl("pb");
		}
		else
			ft_rotate(list_a, len[0], 'a');
		index++;
	}
}

int		ft_len(int pivot, int *list, int len)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (index < len)
	{
		if (pivot < list[index])
			count++;
		index++;
	}
	return (count);
}

int		ft_checkright(int *list_a, int len)
{
	int temp;
	int a;

	temp = list_a[len];
	a = 0;
	if (list_a[0] > list_a[len])
		return (1);
	while (a < len)
	{
		if (list_a[a] > temp)
			return (1);
		a++;
	}
	return (0);
}

void	ft_qsort(int *list_a, int *list_b, int *len)
{
	int lin[4];

	lin[0] = len[0];
	lin[1] = -1;
	lin[2] = -1;
	ft_sort_list_0(list_a, list_b, len, lin);
	ft_main_qsort_a(list_a, list_b, len, lin);
	ft_main_qsort_b(list_a, list_b, len, lin);
	return ;
}
