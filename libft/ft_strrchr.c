/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:43:50 by damboule          #+#    #+#             */
/*   Updated: 2018/11/20 18:46:43 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_check(char *s1, char find, int count)
{
	unsigned int	i;
	int				count_s;

	i = 0;
	count_s = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == find)
			count_s++;
		if (s1[i] == find && count == count_s)
			return (&s1[i]);
		i++;
	}
	return (NULL);
}

char		*ft_strrchr(const char *s1, int c)
{
	unsigned int	i;
	int				count;
	char			find;

	i = 0;
	count = 0;
	find = (char)c;
	s1 = (char*)s1;
	if (find == '\0')
		return ((char*)&s1[ft_strlen(s1)]);
	while (s1[i] != '\0')
	{
		if (s1[i] == find)
			count++;
		i++;
	}
	if (count == 0)
		return (NULL);
	return (ft_check((char*)s1, find, count));
}
