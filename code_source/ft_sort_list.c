/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 15:51:56 by damboule          #+#    #+#             */
/*   Updated: 2019/04/30 11:05:55 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	sort_a(int *list_a, int *list_b, int *len)
{
	ft_push(list_a, list_b, &len[0], &len[1]);
	ft_putendl("pb");
	ft_swap(list_a, 'a');
	ft_push(list_b, list_a, &len[1], &len[0]);
	ft_putendl("pa");
	ft_swap(list_a, 'a');
}

void	sort_b(int *list_a, int *list_b, int *len)
{
	ft_swap(list_a, 'a');
	ft_push(list_a, list_b, &len[0], &len[1]);
	ft_putendl("pb");
	ft_swap(list_a, 'a');
	ft_push(list_b, list_a, &len[1], &len[0]);
	ft_putendl("pa");
	ft_swap(list_a, 'a');
}

void	sort_c(int *list_a, int *len)
{
	ft_swap(list_a, 'a');
	ft_rotate(list_a, len[0], 'a');
	ft_swap(list_a, 'a');
	ft_reverse(list_a, len[0], 'a');
}

void	sort_d(int *list_a, int *len)
{
	ft_rotate(list_a, len[0], 'a');
	ft_swap(list_a, 'a');
	ft_reverse(list_a, len[0], 'a');
}

void	ft_sortlist(int *list_a, int *list_b, int *len)
{
	if (len[0] <= 2)
	{
		if (list_a[0] > list_a[1])
			ft_swap(list_a, 'a');
		return ;
	}
	if (list_a[0] > list_a[1]
	&& list_a[1] < list_a[2] && list_a[0] < list_a[2])
		ft_swap(list_a, 'a');
	else if (list_a[0] < list_a[1]
	&& list_a[1] > list_a[2] && list_a[0] > list_a[2])
		sort_a(list_a, list_b, len);
	else if (list_a[0] > list_a[1]
	&& list_a[1] > list_a[2] && list_a[0] > list_a[2])
		sort_b(list_a, list_b, len);
	else if (list_a[0] > list_a[1]
	&& list_a[1] < list_a[2] && list_a[0] > list_a[2])
		sort_c(list_a, len);
	else if (list_a[0] < list_a[1]
	&& list_a[1] > list_a[2] && list_a[0] < list_a[2])
		sort_d(list_a, len);
}
