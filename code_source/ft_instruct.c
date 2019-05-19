/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:29:35 by damboule          #+#    #+#             */
/*   Updated: 2019/04/30 20:09:01 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

void	ft_free(char **tab)
{
	int a;

	a = 0;
	while (tab[a])
	{
		free(tab[a]);
		tab[a] = NULL;
		a++;
	}
	free(tab[a]);
	tab[a] = NULL;
}

int		ft_end(char *num)
{
	if (ft_strncmp(num, "rrr", 3) == 0 && ft_strlen(num) == 3)
		return (1);
	else if (ft_strncmp(num, "rr", 2) == 0 && ft_strlen(num) == 2)
		return (1);
	else if (ft_strncmp(num, "ss", 2) == 0 && ft_strlen(num) == 2)
		return (1);
	return (0);
}

int		ft_check_instruc(char *num)
{
	if ((ft_strncmp(num, "sa", 2) == 0
	|| ft_strncmp(num, "sb", 2) == 0) && ft_strlen(num) == 2)
		return (0);
	else if ((ft_strncmp(num, "pa", 2) == 0
	|| ft_strncmp(num, "pb", 2) == 0) && ft_strlen(num) == 2)
		return (0);
	else if ((ft_strncmp(num, "ra", 2) == 0
	|| ft_strncmp(num, "rb", 2) == 0) && ft_strlen(num) == 2)
		return (0);
	else if ((ft_strncmp(num, "rra", 3) == 0
	|| ft_strncmp(num, "rrb", 3) == 0) && ft_strlen(num) == 3)
		return (0);
	else if (ft_end(num))
		return (0);
	return (1);
}

int		ft_stop_error(char *instruct, char *a_free)
{
	ft_putstr("Error\n");
	a_free = NULL;
	instruct = NULL;
	free(a_free);
	free(instruct);
	exit(1);
}
