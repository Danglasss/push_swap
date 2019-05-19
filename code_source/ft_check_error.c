/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 17:24:23 by damboule          #+#    #+#             */
/*   Updated: 2019/04/16 13:35:16 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_letter(char *tab)
{
	int a;

	a = 0;
	while (tab[a])
	{
		if ((!(tab[a] <= 57 && tab[a] >= 48)))
		{
			if ((tab[a] != ' ' && tab[a] != '-')
			|| (tab[a] == '-' && (!(tab[a + 1] <= 57 && tab[a + 1] >= 48))))
			{
				ft_putstr("Error\n");
				return (1);
			}
		}
		a++;
	}
	return (0);
}

int		ft_letter_tab(char **tab, int argc)
{
	int a;
	int b;

	a = 0;
	b = 1;
	while (b < argc)
	{
		while (tab[b][a])
		{
			if ((!(tab[b][a] <= 57 && tab[b][a] >= 48)))
			{
				if (tab[b][a] != '-' || (tab[b][a] == '-' &&
				(!(tab[b][a + 1] <= 57 && tab[b][a + 1] >= 48))))
				{
					ft_putstr("Error\n");
					return (1);
				}
			}
			a++;
		}
		b++;
		a = 0;
	}
	return (0);
}

long	ft_atoi_long(char *str)
{
	int		index;
	long	neg;
	long	numero;

	neg = 1;
	index = 0;
	numero = 0;
	if (str[index] == '-')
	{
		index++;
		neg = -1;
	}
	while (str[index] && (str[index] >= '0' && str[index] <= '9'))
	{
		numero = (numero * 10) + (str[index] - '0');
		index++;
	}
	return (numero * neg);
}

int		ft_error(char **content)
{
	int		index;
	long	conversion;

	index = 0;
	while (content[index])
	{
		conversion = ft_atoi_long(content[index]);
		if (conversion < -2147483648 || conversion > 2147483647)
			return (1);
		index++;
	}
	return (0);
}

int		ft_doublon(int *list_a, int len)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a <= len)
	{
		while (b <= len)
		{
			if (list_a[a] == list_a[b] && a != b)
				return (1);
			b++;
		}
		a++;
		b = 0;
	}
	return (0);
}
