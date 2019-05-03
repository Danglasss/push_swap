/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 13:28:00 by damboule          #+#    #+#             */
/*   Updated: 2019/04/15 13:01:19 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_checks(int *list, int len)
{
	int index;

	index = 0;
	while (index < len - 1)
	{
		if (list[index] > list[index + 1])
			return (0);
		index++;
	}
	return (1);
}

int		ft_check_sort(int *list, int len)
{
	int index;

	index = 0;
	if (len == 0)
		return (1);
	if (len == -1)
		return (0);
	while (index < len)
	{
		if (list[index] > list[index + 1])
			return (0);
		index++;
	}
	return (1);
}

int		ft_check_sort_a(int *list, int *len)
{
	int a;
	int b;

	a = 0;
	b = len[1];
	while (a < len[0])
	{
		if (list[a] > list[a + 1])
			return (1);
		a++;
	}
	return (0);
}

void	ft_join_list(int *list_a, int *list_b, int *len)
{
	int index;

	index = len[1];
	while (index >= 0)
	{
		ft_push(list_b, list_a, &len[1], &len[0]);
		ft_putendl("pa");
		index--;
	}
	len[1] = -1;
	return ;
}

int		ft_path_step(int len, int index, char letter)
{
	int path;

	path = 0;
	if (letter == 'u')
	{
		while (index-- > 0)
			path++;
		return (path);
	}
	if (letter == 'd')
	{
		while (index++ < len)
			path++;
		return (path + 1);
	}
	return (path);
}
