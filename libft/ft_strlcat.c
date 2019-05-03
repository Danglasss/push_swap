/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:06:39 by damboule          #+#    #+#             */
/*   Updated: 2018/11/13 18:08:02 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	size_t	index;
	size_t	a;
	size_t	b;
	size_t	c;

	c = ft_strlen(src);
	a = ft_strlen(dst);
	index = a + c;
	if (size < a)
		index = size + c;
	b = 0;
	if (size != 0)
		size = size - 1;
	while (a < index && a < size && src[b] != '\0')
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (index);
}
