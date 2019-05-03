/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:22:29 by damboule          #+#    #+#             */
/*   Updated: 2018/12/03 15:23:23 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrnlen(const char *s, char occurency, int len)
{
	int find;
	int	index;

	find = 0;
	index = 0;
	if (occurency == '\0' || (!(s)) || s == NULL)
		return (find);
	while (s[index] != '\0' && len > 0)
	{
		if (s[index] == occurency)
			find = find + 1;
		len--;
		index++;
	}
	return (find);
}
