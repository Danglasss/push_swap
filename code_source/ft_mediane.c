/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:15:12 by damboule          #+#    #+#             */
/*   Updated: 2019/04/10 17:04:26 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_nb_chiffre(int *list, int len, int sens)
{
	int a;
	int b;
	int index;

	index = 0;
	a = list[index];
	b = list[index];
	while (++index < len)
	{
		if ((list[index] != a && list[index] != b) && a != b)
			return (0);
		else if ((list[index] != a && list[index] != b) && a == b)
			b = list[index];
	}
	if ((sens == 1 && a < b) || (sens == 2 && a > b))
		return (a);
	return (b);
}

int		ft_find_mediane(int *list, int len, int sens)
{
	int nb_chiffre;

	nb_chiffre = ft_nb_chiffre(list, len, sens);
	if (nb_chiffre != 0)
		return (nb_chiffre);
	if (len % 2 == 0)
		return (list[len / 2]);
	return ((list[len / 2] + list[(len / 2) + 1]) / 2);
}

void	ft_intdup(int *list_o, int *list, int len)
{
	int index;

	index = 0;
	while (index <= len)
	{
		list[index] = list_o[index];
		index++;
	}
}

int		ft_mediane(int *list_o, int len, int sens)
{
	int index_a;
	int index_b;
	int list[len + 1];
	int temp;

	ft_intdup(list_o, list, len);
	index_a = 0;
	index_b = 1;
	while (index_a < len)
	{
		while (index_b < len + 1)
		{
			if (list[index_b] < list[index_a])
			{
				temp = list[index_a];
				list[index_a] = list[index_b];
				list[index_b] = temp;
			}
			index_b++;
		}
		index_a++;
		index_b = index_a + 1;
	}
	return (ft_find_mediane(list, len, sens));
}
