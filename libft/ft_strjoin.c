/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:53:19 by damboule          #+#    #+#             */
/*   Updated: 2018/11/26 22:10:38 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_join(int len, int length, char const *s1, char const *s2)
{
	char	*buffer;
	int		index;

	index = 0;
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	buffer = ft_strcpy(buffer, s1);
	while (s2[index] != '\0')
	{
		buffer[length] = s2[index];
		length++;
		index++;
	}
	buffer[length] = '\0';
	return (buffer);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (ft_strdup(s1));
	if (s1 == NULL)
		return (ft_strdup(s2));
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	return (ft_join(len, a, s1, s2));
}
