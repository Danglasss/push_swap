/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:40:02 by damboule          #+#    #+#             */
/*   Updated: 2018/11/28 13:13:32 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

static char	*ft_check(char *s1, char *s2)
{
	if (s1 == NULL)
		return (s2);
	if (s2 == NULL)
		return (s1);
	return (NULL);
}

static char	*ft_copy(char *resolution, int i, char *s2, size_t n)
{
	size_t a;

	a = 0;
	while (s2[a] != '\0' && a < n)
	{
		resolution[i] = s2[a];
		i++;
		a++;
	}
	resolution[i] = '\0';
	return (resolution);
}

char		*ft_strncat(char *s1, char *s2, size_t n)
{
	char	*resolution;
	int		i;
	int		index;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (ft_check(s1, s2));
	index = ft_strlen(s1);
	resolution = (char *)malloc(sizeof(char) * (index + n) + 1);
	if (resolution == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		resolution[i] = s1[i];
		i++;
	}
	return (ft_copy(resolution, i, s2, n));
}
