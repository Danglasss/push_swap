/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:54:28 by damboule          #+#    #+#             */
/*   Updated: 2018/11/24 16:53:05 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*buff;

	i = 0;
	if (s == NULL && *s == '\0')
		return (NULL);
	buff = (char*)malloc(sizeof(char) * len + 1);
	if (buff == NULL)
		return (NULL);
	while (len--)
		buff[i++] = s[start++];
	buff[i] = '\0';
	return (buff);
}
