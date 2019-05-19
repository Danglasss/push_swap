/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 17:27:06 by damboule          #+#    #+#             */
/*   Updated: 2019/04/30 17:48:33 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int			ft_path_first(int *list_a, int len_a, int index)
{
	int instruct_up;
	int instruct_down;

	if (index == 1)
	{
		ft_swap(list_a, 'a');
		return (1);
	}
	instruct_up = ft_path_step(len_a, index, 'u');
	instruct_down = ft_path_step(len_a, index, 'd');
	while (instruct_up > 0 && instruct_down > 0)
	{
		if (instruct_down >= instruct_up)
			ft_rotate(list_a, len_a, 'a');
		else if (instruct_up > instruct_down)
			ft_reverse(list_a, len_a, 'a');
		instruct_down--;
		instruct_up--;
	}
	return (1);
}

void		ft_sort_ra(int *list_a, int *list_b, int *len, int *lin)
{
	int pivot_mix;
	int	index;
	int count;

	lin[1] = lin[3];
	pivot_mix = ft_mediane(list_b, lin[1], 1);
	index = -1;
	count = 0;
	while (++index < lin[1])
	{
		if (list_b[0] < list_b[1])
			ft_make_swap(list_a, list_b, len);
		if (list_b[0] >= pivot_mix)
		{
			ft_push(list_b, list_a, &len[1], &len[0]);
			ft_putendl("pa");
		}
		else if (ft_countlen(list_b, lin[1] + 1, index, pivot_mix)
		&& count++ > -1)
			ft_rotate(list_b, len[1], 'b');
	}
	while (list_b[0] > list_b[1] && count-- > 0)
		ft_reverse(list_b, len[1], 'b');
}

void		ft_sort_rb(int *list_a, int *list_b, int *len, int *lin)
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
		if (list_a[0] > list_a[1] && index != len_a)
			ft_make_swap(list_a, list_b, len);
		if (list_a[0] < pivot_mix && (lin[3] = lin[3] + 1) > -1)
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

int			ft_qsort_b(int *list_a, int *list_b, int *len, int *lin)
{
	if (len[1] == 0)
	{
		ft_push(list_b, list_a, &len[1], &len[0]);
		ft_putendl("pa");
	}
	if (len[0] > len[3] && ft_check_sort(list_a, len[0]))
		return (len[0]);
	ft_sort_ra(list_a, list_b, len, lin);
	lin[3] = 0;
	lin[0] = ft_len_sort(list_a, len[0], lin[0], -1);
	ft_sort_rb(list_a, list_b, len, lin);
	lin[3] = 0;
	lin[0] = ft_len_sort(list_a, len[0], lin[0], -1);
	ft_sort_rb(list_a, list_b, len, lin);
	ft_qsort_b(list_a, list_b, len, lin);
	return (len[0]);
}

void		ft_main_qsort_b(int *list_a, int *list_b, int *len, int *lin)
{
	int count;

	count = 0;
	lin[0] = 0;
	lin[1] = -1;
	lin[2] = len[0];
	len[3] = len[0];
	while (count == 0)
	{
		lin[3] = len[1];
		lin[0] = ft_qsort_b(list_a, list_b, len, lin);
		lin[3] = len[1];
		len[3] = lin[0];
		if (len[1] == -1)
			return ;
	}
}
