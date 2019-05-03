/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:33:16 by danglass          #+#    #+#             */
/*   Updated: 2019/04/15 15:58:40 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_sort_list_b(int *list_a, int *list_b, int *len, int *index)
{
	int path_up;
	int path_down;
	int len_b;
	int chiffre;

	len_b = len[1];
	chiffre = list_a[index[2]];
	if (chiffre < list_b[0])
	{
		if (len_b == -1 || len_b == 0)
			return (0);
		path_down = ft_check_down(list_b, len_b, chiffre);
		path_up = ft_check_up(list_b, len_b, chiffre);
		if (path_up <= path_down)
		{
			while (path_up-- > 0)
				ft_rotate(list_b, len[1], 'b');
			return (1);
		}
		while (path_down-- > 0)
			ft_reverse(list_b, len[1], 'b');
		return (2);
	}
	return (0);
}

void	ft_sort_list(int *list_a, int *list_b, int *len)
{
	int count;
	int pivot_a[4];
	int index;

	pivot_a[1] = ft_mediane(list_a, len[0], 2);
	index = -1;
	count = 0;
	while (++index <= len[0] && ft_number_a(list_a, len[0]))
	{
		if (list_a[index] < pivot_a[1] && index == 0)
		{
			pivot_a[2] = index;
			pivot_a[3] = ft_sort_list_b(list_a, list_b, len, pivot_a);
			ft_push(list_a, list_b, &len[0], &len[1]);
			ft_putendl("pb");
			ft_sort_back(list_b, list_a, len, pivot_a[3]);
			index = -1;
		}
		else if (index != -1 && list_a[index] < pivot_a[1])
		{
			if (ft_path_first(list_a, len[0], index))
				index = -1;
		}
	}
	ft_sort_list_a(list_a);
}

void	ft_selectsort(int *list_a, int *list_b, int *len)
{
	while (ft_check_sort_a(list_a, len))
		ft_sort_list(list_a, list_b, len);
	ft_join_list(list_a, list_b, len);
	return ;
}
