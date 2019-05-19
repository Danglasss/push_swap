/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:49:21 by damboule          #+#    #+#             */
/*   Updated: 2018/11/20 21:52:07 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tab;
	int		i;

	if (!s)
		return (0);
	tab = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		tab[i] = f(s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
