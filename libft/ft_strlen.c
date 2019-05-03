/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:43:02 by damboule          #+#    #+#             */
/*   Updated: 2018/11/23 21:02:21 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str == NULL || (!(str)))
		return (0);
	while (str[i])
	{
		if (str[i + 1] == '\0')
			return (i + 1);
		else if (str[i + 2] == '\0')
			return (i + 2);
		else if (str[i + 3] == '\0')
			return (i + 3);
		else if (str[i + 4] == '\0')
			return (i + 4);
		i += 4;
	}
	return (i);
}
