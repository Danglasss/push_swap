/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:09:08 by damboule          #+#    #+#             */
/*   Updated: 2019/05/17 13:37:11 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/assembly.h"

int		ft_end_sort(int *list_a, int *list_b, int *len, char *num)
{
	if (ft_strncmp(num, "rrr", 3) == 0 && ft_strlen(num) == 3)
	{
		ft_reverse_all_checker(list_a, list_b, len);
		return (0);
	}
	else if (ft_strncmp(num, "rr", 2) == 0 && ft_strlen(num) == 2)
	{
		ft_rotate_all_checker(list_a, list_b, len);
		return (0);
	}
	else if (ft_strncmp(num, "ss", 2) == 0 && ft_strlen(num) == 2)
	{
		ft_swap_all_checker(list_a, list_b);
		return (0);
	}
	return (1);
}

void	ft_make_sort(int *l_a, int *list_b, int *len, char **num)
{
	int index;

	index = -1;
	while (num[++index])
	{
		if ((ft_strncmp(num[index], "sa", 2) == 0
		|| ft_strncmp(num[index], "sb", 2) == 0) && ft_strlen(num[index]) == 2)
			ft_swap_checker(l_a, list_b, num[index]);
		else if ((ft_strncmp(num[index], "pa", 2) == 0
		|| ft_strncmp(num[index], "pb", 2) == 0) && ft_strlen(num[index]) == 2)
			ft_push_checker(l_a, list_b, len, num[index]);
		else if ((ft_strncmp(num[index], "ra", 2) == 0
		|| ft_strncmp(num[index], "rb", 2) == 0) && ft_strlen(num[index]) == 2)
			ft_rotate_checker(l_a, list_b, len, num[index]);
		else if ((ft_strncmp(num[index], "rra", 3) == 0
		|| ft_strncmp(num[index], "rrb", 3) == 0) && ft_strlen(num[index]) == 3)
			ft_reverse_checker(l_a, list_b, len, num[index]);
		else if (ft_end_sort(l_a, list_b, len, num[index]))
			return ;
	}
	ft_free(num);
	free(num);
	ft_checker_sort(l_a, len[0], len[1]);
}

int		get_line(char *instruct, char *a_free)
{
	char	buffer;
	int		i;
	char	*test;
	int		retour;

	i = 0;
	test = NULL;
	while (((retour = read(0, test, 0)) != -1) && read(0, &buffer, 1) > 0)
	{
		instruct[i] = buffer;
		if (instruct[i] == '\n')
		{
			instruct[i] = '\0';
			if (ft_check_instruc(instruct))
				ft_stop_error(instruct, a_free);
			return (1);
		}
		i++;
	}
	if (i > 0 || retour == -1)
		ft_stop_error(instruct, a_free);
	return (0);
}

char	**ft_instruct(void)
{
	char **content_back;
	char *content;
	char *instruct;

	if (!(content = malloc(sizeof(char) * 10)))
		return (NULL);
	if (!(instruct = malloc(sizeof(char) * 10)))
		return (NULL);
	while (get_line(content, instruct))
	{
		if (instruct[0] != '\0')
			instruct = ft_strjoin_free_s1(instruct, " ");
		instruct = ft_strjoin_free_s1(instruct, content);
		ft_bzero(content, 10);
	}
	content_back = ft_strsplit(instruct, ' ');
	free(instruct);
	free(content);
	return (content_back);
}

void	ft_restore(int *list_a, int *list_b, int *len, char **nombre)
{
	char	**instruct;
	int		index;
	int		i;

	index = 0;
	i = -1;
	ft_check_erreur(list_a, len, nombre);
	instruct = ft_instruct();
	ft_check_erreur_sort(list_a, len, instruct);
	ft_make_sort(list_a, list_b, len, instruct);
}
