/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:55:44 by damboule          #+#    #+#             */
/*   Updated: 2018/11/28 12:56:48 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub_free(char *s, unsigned int start, size_t len)
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
	free(s);
	s = NULL;
	return (buff);
}
