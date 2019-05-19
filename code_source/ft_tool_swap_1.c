/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_swap_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 21:17:55 by damboule          #+#    #+#             */
/*   Updated: 2019/03/22 17:05:18 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	ft_check_reverse(int *list_a, int *list_b, int *len)
{
	if (list_b[1] > list_b[0] && list_b[len[1]] >= list_b[0])
	{
		if (list_a[0] > list_a[1])
		{
			ft_rotate_all(list_a, list_b, len[0], len[1]);
			return ;
		}
		ft_rotate(list_b, len[1], 'b');
		return ;
	}
	while (list_b[0] <= list_b[len[1]])
	{
		if (list_a[0] > list_a[1])
			ft_reverse_all(list_a, list_b, len[0], len[1]);
		else
			ft_reverse(list_b, len[1], 'b');
	}
	return ;
}

void	ft_check_rotate(int *list_a, int *list_b, int *len)
{
	if (list_b[1] > list_b[0] && list_b[len[1]] >= list_b[0])
	{
		if (list_a[0] > list_a[1])
		{
			ft_rotate_all(list_a, list_b, len[0], len[1]);
			return ;
		}
		ft_rotate(list_b, len[1], 'b');
		return ;
	}
	while (list_b[0] <= list_b[len[1]])
	{
		if (list_a[0] > list_a[1])
			ft_rotate_all(list_a, list_b, len[0], len[1]);
		else
			ft_rotate(list_b, len[1], 'b');
	}
	return ;
}

void	ft_sort_back(int *list_b, int *list_a, int *len, int sens)
{
	if (len[1] == 1 && list_b[0] < list_b[1])
	{
		if (list_a[0] > list_a[1])
			ft_swap_all(list_b, list_a);
		else
			ft_swap(list_b, 'b');
	}
	if (sens != 0)
	{
		if (sens == 1)
		{
			ft_check_reverse(list_a, list_b, len);
			return ;
		}
		if (sens == 2)
		{
			ft_check_rotate(list_a, list_b, len);
			return ;
		}
	}
	return ;
}

int		ft_check_up(int *list, int len, int chiffre)
{
	int index;

	index = 0;
	if (list[0] > chiffre && list[len] >= chiffre)
		return (0);
	while (index < len)
	{
		if (chiffre <= list[index] && chiffre >= list[index + 1])
			return (index + 1);
		index++;
	}
	return (index);
}

int		ft_check_down(int *list, int len, int chiffre)
{
	int count;

	count = 0;
	if (list[0] > chiffre && list[len] >= chiffre)
		return (0);
	while (len > 0)
	{
		if (chiffre <= list[len] && chiffre >= list[len - 1])
			return (count);
		len--;
		count++;
	}
	return (count);
}
