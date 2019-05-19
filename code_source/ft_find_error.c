/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dechet_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 22:11:42 by damboule          #+#    #+#             */
/*   Updated: 2019/04/30 19:21:15 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_check_erreur(int *list_a, int *len, char **nombre)
{
	if (ft_doublon(list_a, len[0]) || ft_error(nombre))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return (0);
}

int		ft_check_erreur_sort(int *list_a, int *len, char **i)
{
	int vide;

	vide = ft_strtab((const char **)i);
	if (vide == 0 && ft_check_sort(list_a, len[0]))
	{
		ft_putstr("OK\n");
		ft_free(i);
		free(i);
		exit(1);
	}
	else if (vide == 0 || (vide != 0 && ft_check_sort(list_a, len[0])))
	{
		ft_putstr("KO\n");
		ft_free(i);
		free(i);
		exit(1);
	}
	return (0);
}

int		ft_checker_sort(int *list, int len, int len_b)
{
	int index;

	index = 0;
	if (len_b != -1)
	{
		ft_putstr("KO\n");
		return (0);
	}
	while (index < len)
	{
		if (list[index] > list[index + 1])
		{
			ft_putstr("KO\n");
			return (0);
		}
		index++;
	}
	ft_putstr("OK\n");
	return (0);
}

void	ft_putintn(int *list_a, int len)
{
	int index;

	index = 0;
	while (index <= len)
	{
		ft_putnbr(list_a[index]);
		if (index != len)
			ft_putstr("  ");
		index++;
	}
	ft_putchar('\n');
}
