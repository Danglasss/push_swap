/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operateur_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:32:50 by damboule          #+#    #+#             */
/*   Updated: 2019/04/10 17:02:47 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

/*
** a faire
*/

void	ft_swap_checker(int *list_a, int *list_b, char *l, int *len)
{
	int	swap;

	if (ft_strncmp(l, "sa", 2) == 0 && len[0] >= 1)
	{
		swap = list_a[0];
		list_a[0] = list_a[1];
		list_a[1] = swap;
	}
	else if (ft_strncmp(l, "sb", 2) == 0 && len[1] >= 1)
	{
		swap = list_b[0];
		list_b[0] = list_b[1];
		list_b[1] = swap;
	}
	return ;
}

void	ft_push_checker(int *list_a, int *list_b, int *len, char *l)
{
	if (ft_strncmp(l, "pb", 2) == 0 && len[0] >= 0)
		ft_push(list_a, list_b, &len[0], &len[1]);
	else if (ft_strncmp(l, "pa", 2) == 0 && len[1] >= 0)
		ft_push(list_b, list_a, &len[1], &len[0]);
	return ;
}

void	ft_rotate_checker(int *list_a, int *list_b, int *len, char *l)
{
	int swap;
	int index;

	if (len[0] >= 1)
		swap = list_a[0];
	index = -1;
	if (ft_strncmp(l, "ra", 2) == 0 && len[0] >= 1)
	{
		while (++index < len[0])
			list_a[index] = list_a[index + 1];
		list_a[len[0]] = swap;
	}
	if (len[1] >= 1)
		swap = list_b[0];
	index = -1;
	if (ft_strncmp(l, "rb", 2) == 0 && len[1] >= 1)
	{
		while (++index < len[1])
			list_b[index] = list_b[index + 1];
		list_b[len[1]] = swap;
	}
}

void	ft_reverse_checker(int *list_a, int *list_b, int *len, char *l)
{
	int swap;
	int count;

	if ((ft_strncmp(l, "rra", 3) == 0 || ft_strncmp(l, "r", 3) == 0)
	&& len[0] >= 1)
	{
		count = len[0] + 1;
		swap = list_a[len[0]];
		while (--count > 0)
			list_a[count] = list_a[count - 1];
		list_a[0] = swap;
	}
	if ((ft_strncmp(l, "rrb", 3) == 0 || ft_strncmp(l, "r", 3) == 0)
	&& len[1] >= 1)
	{
		count = len[1] + 1;
		swap = list_b[len[1]];
		while (--count > 0)
			list_b[count] = list_b[count - 1];
		list_b[0] = swap;
	}
}
