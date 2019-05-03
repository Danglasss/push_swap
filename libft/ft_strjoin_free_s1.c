/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_s1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:40:27 by damboule          #+#    #+#             */
/*   Updated: 2019/05/01 12:29:05 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_join_s1(int len, int length, char *s1, char const *s2)
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
	free(s1);
	s1 = NULL;
	return (buffer);
}

char		*ft_strjoin_free_s1(char *s1, char const *s2)
{
	int		a;
	int		b;
	int		len;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s2 == NULL)
		return (s1);
	if (s1 == NULL)
		return (ft_strdup(s2));
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	len = ft_strlen(s1) + ft_strlen(s2);
	return (ft_join_s1(len, a, s1, s2));
}
