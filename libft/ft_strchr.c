/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 17:07:24 by damboule          #+#    #+#             */
/*   Updated: 2018/11/13 11:16:10 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	find;

	i = 0;
	find = (char)c;
	s = (char*)s;
	if (find == '\0')
		return ((char*)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == find)
			return ((char*)&s[i]);
		i++;
	}
	return (NULL);
}
