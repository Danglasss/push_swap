/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:31:09 by damboule          #+#    #+#             */
/*   Updated: 2018/12/03 02:25:08 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchar(char *str, char occurency)
{
	int	i;

	i = 0;
	while (str[i] != '\0' & str[i] != occurency)
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
