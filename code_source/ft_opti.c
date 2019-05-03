/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 17:28:04 by damboule          #+#    #+#             */
/*   Updated: 2019/02/07 17:31:00 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	ft_sort_list_a(int *list_a)
{
	if (list_a[0] > list_a[1])
		ft_swap(list_a, 'a');
	return ;
}

int		ft_number_a(int *list, int len)
{
	int a;
	int num;

	a = 0;
	num = list[a];
	while (a < len)
	{
		if (list[a] != num)
			return (1);
		a++;
	}
	return (0);
}
