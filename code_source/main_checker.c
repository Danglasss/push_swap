/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:27:56 by damboule          #+#    #+#             */
/*   Updated: 2019/04/30 13:09:18 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	ft_recorve_checker(int *len, int size, char **argv, int argc)
{
	int list_a[size + 1];
	int list_b[size + 1];
	int index;

	index = 0;
	len[0] = size - 1;
	len[1] = -1;
	if (argc < 2 || ft_letter_tab(argv, argc))
		return ;
	while (index < size)
	{
		list_a[index] = 0;
		if (index + 1 < argc)
			list_a[index] = ft_atoi(argv[index + 1]);
		index++;
	}
	ft_restore(list_a, list_b, len, &argv[1]);
}

void	ft_recorvery_checker(int *len, int size, char **nombre, char **arg)
{
	int list_a[size + 1];
	int list_b[size + 1];
	int index;

	index = 0;
	len[0] = size - 1;
	len[1] = -1;
	if (ft_letter(arg[1]))
		return ;
	while (index < size)
	{
		list_a[index] = 0;
		list_a[index] = ft_atoi(nombre[index]);
		index++;
	}
	ft_restore(list_a, list_b, len, nombre);
}

int		main(int argc, char **argv)
{
	int		len[3];
	int		size;
	char	**nombre;

	if (argc == 2)
	{
		nombre = ft_strsplit(argv[1], ' ');
		size = ft_strtab((const char **)nombre);
		ft_recorvery_checker(len, size, nombre, argv);
		return (0);
	}
	size = argc - 1;
	ft_recorve_checker(len, size, argv, argc);
	return (0);
}
