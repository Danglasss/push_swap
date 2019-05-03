/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:24:41 by damboule          #+#    #+#             */
/*   Updated: 2019/04/30 12:21:41 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_compte(int pivot, int sens, int *list, int len)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (index < len)
	{
		if (sens == 1 && list[index] < pivot)
			count++;
		else if (sens == 2 && list[index] > pivot)
			count++;
		index++;
	}
	return (count);
}

void	ft_sort_swap(int *list_a, int *list_b, int *len)
{
	list_b = list_a;
	if (list_a[0] > list_a[1] && list_a[0] < list_a[2])
	{
		ft_swap(list_a, len[0]);
		ft_putendl("sa");
		return ;
	}
	if (list_a[2] > list_a[3])
		ft_rotate(list_a, len[0], 'a');
	while (list_a[0] > list_a[len[0]])
		ft_rotate(list_a, len[0], 'a');
	if (list_a[0] > list_a[1])
	{
		ft_swap(list_a, len[0]);
		ft_putendl("sa");
	}
}

void	ft_redirection(int *list_a, int *list_b, int *len, char **nombre)
{
	if (ft_check_erreur(list_a, len, nombre) || len[0] == 0)
		return ;
	else if (ft_check_sort(list_a, len[0]))
		return ;
	else if (len[0] <= 3)
		ft_sort_swap(list_a, list_b, len);
	else if (len[0] >= 4 && len[0] <= 10)
		ft_selectsort(list_a, list_b, len);
	else if (len[0] >= 40 && len[0] < 139)
		ft_qsort(list_a, list_b, len);
	else if (len[0] > 139)
		main_quicksort(list_a, list_b, len);
}
