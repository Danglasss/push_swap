/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_sort_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:36:22 by damboule          #+#    #+#             */
/*   Updated: 2019/04/30 18:18:59 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	ft_sort_a(int *list_a, int *list_b, int *len, int *lin)
{
	int pivot_mix;
	int	index;
	int count;

	lin[1] = lin[3];
	pivot_mix = ft_mediane(list_b, lin[1], 1);
	index = -1;
	count = 0;
	while (ft_countlen(list_b, len[1], index, pivot_mix) && ++index < lin[1])
	{
		if (list_b[0] < list_b[1] || list_a[0] > list_a[1])
			ft_make_swap(list_a, list_b, len);
		if (list_b[0] > pivot_mix)
		{
			ft_push(list_b, list_a, &len[1], &len[0]);
			ft_putendl("pa");
		}
		else
		{
			ft_rotate(list_b, len[1], 'b');
			count++;
		}
	}
	while (count-- > 0)
		ft_reverse(list_b, len[1], 'b');
}

void	ft_sort_b(int *list_a, int *list_b, int *len, int *lin)
{
	int pivot_mix;
	int	index;
	int len_a;
	int count;

	len_a = (len[0] - lin[0]) + 1;
	pivot_mix = ft_mediane(list_a, len_a, 2);
	index = -1;
	count = 0;
	while (++index <= len_a)
	{
		if (ft_check_sort(list_a, len[0]))
			return ;
		if ((list_a[0] > list_a[1] || list_b[0] < list_b[1]) && index != len_a)
			ft_make_swap(list_a, list_b, len);
		if (list_a[0] <= pivot_mix && (lin[3] = lin[3] + 1) > -1)
		{
			ft_push(list_a, list_b, &len[0], &len[1]);
			ft_putendl("pb");
		}
		else if (ft_countlen_a(list_a, len_a, index, pivot_mix) && count++ > -1)
			ft_rotate(list_a, len[0], 'a');
	}
	while (ft_checkright(list_a, len[0]) && count-- > 0)
		ft_reverse(list_a, len[0], 'a');
}

int		ft_qsort_a(int *list_a, int *list_b, int *len, int *lin)
{
	len[3] = len[3] + 1;
	if (ft_check_sort(list_a, len[0]))
		return (len[0]);
	if (len[3] >= 1)
		ft_sort_a(list_a, list_b, len, lin);
	lin[3] = 0;
	lin[0] = ft_len_sort(list_a, len[0], lin[0], -1);
	ft_sort_b(list_a, list_b, len, lin);
	lin[3] = 0;
	lin[0] = ft_len_sort(list_a, len[0], lin[0], -1);
	ft_sort_b(list_a, list_b, len, lin);
	ft_qsort_a(list_a, list_b, len, lin);
	return (len[0]);
}

void	ft_main_qsort_a(int *list_a, int *list_b, int *len, int *lin)
{
	int count;

	count = 0;
	lin[0] = 0;
	lin[2] = len[0];
	while (!(ft_check_sort(list_a, lin[2])))
	{
		len[3] = -1;
		lin[0] = ft_qsort_a(list_a, list_b, len, lin);
		lin[3] = lin[2] - len[0];
		if (!(ft_check_sort(list_a, lin[2])))
			ft_sort_a(list_a, list_b, len, lin);
		count++;
	}
}
