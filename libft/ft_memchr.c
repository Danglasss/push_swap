/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:50:54 by damboule          #+#    #+#             */
/*   Updated: 2018/11/14 11:32:27 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*string;
	unsigned char		occurency;
	void				*e;

	occurency = (unsigned char)c;
	string = (const unsigned char*)s;
	e = (void*)s;
	while (n-- > 0 && *string != '\0')
	{
		if (*string == occurency)
			return (e);
		e++;
		string++;
		if (*string == occurency && occurency == '\0')
			return (e);
	}
	return (NULL);
}
