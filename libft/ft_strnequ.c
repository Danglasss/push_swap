/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:49:39 by damboule          #+#    #+#             */
/*   Updated: 2018/11/14 20:13:04 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i] && i < n)
	{
		if ((s1[i] - s2[i]) != 0)
			return (0);
		i++;
	}
	if ((s1[i] == '\0' && s2[i] == '\0') || n == i)
		return (1);
	return (0);
}
