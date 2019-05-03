/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_ope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 11:56:43 by damboule          #+#    #+#             */
/*   Updated: 2019/04/10 17:00:46 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_calcul(int *list_a, int pivot, int real_index, int index)
{
	while (list_a[index] > pivot)
	{
		index++;
		if (index == real_index)
			index++;
	}
	return (index);
}

void	ft_try_rotate(int *list_a, int *list_b, int *len, int *index)
{
	int value;
	int path_a;
	int path_b;

	value = ft_calcul(list_a, index[1], index[2], 0);
	path_a = ft_path_step(len[0], value, 'u');
	path_b = ft_path_step(len[0], value, 'd');
	if (path_a < path_b)
	{
		ft_rotate_all(list_a, list_b, len[0], len[1]);
		return ;
	}
	ft_rotate(list_a, len[0], 'a');
}

void	ft_try_reverse(int *list_a, int *list_b, int *len, char letter)
{
	if (letter == 'a')
	{
		if (list_b[0] > list_b[len[1]])
			ft_reverse_all(list_a, list_b, len[0], len[1]);
		else
			ft_reverse(list_a, len[0], 'a');
	}
	else
		ft_reverse(list_b, len[1], 'b');
	return ;
}

void	ft_try_swap(int *list_a, int *list_b)
{
	if (list_a[0] > list_a[1] && list_b[0] < list_b[1])
		ft_swap_all(list_a, list_b);
	else if (list_a[0] > list_a[1])
		ft_swap(list_a, 'a');
	else if (list_b[0] < list_b[1])
		ft_swap(list_b, 'b');
	return ;
}
