/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operateur_checker_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:32:42 by damboule          #+#    #+#             */
/*   Updated: 2019/04/10 17:02:31 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	ft_rotate_all_checker(int *list_a, int *list_b, int *len)
{
	int swap;
	int count;

	count = 0;
	swap = list_a[0];
	while (count < len[0])
	{
		list_a[count] = list_a[count + 1];
		count++;
	}
	list_a[len[0]] = swap;
	count = 0;
	swap = list_b[0];
	while (count < len[1])
	{
		list_b[count] = list_b[count + 1];
		count++;
	}
	list_b[len[1]] = swap;
}

void	ft_swap_all_checker(int *list_a, int *list_b)
{
	int swap;

	swap = list_a[0];
	list_a[0] = list_a[1];
	list_a[1] = swap;
	swap = list_b[0];
	list_b[0] = list_b[1];
	list_b[1] = swap;
	return ;
}
