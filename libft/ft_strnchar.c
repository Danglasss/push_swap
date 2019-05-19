/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 02:22:21 by damboule          #+#    #+#             */
/*   Updated: 2018/12/03 02:24:02 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnchar(char *str, char occurency, int len)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != occurency && i < len)
	{
		if (str[i] == occurency)
			return (i);
		i++;
		if (str[i] == occurency)
			return (i);
	}
	if (str[i] == occurency)
		return (i);
	return (-1);
}
