/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:00:19 by damboule          #+#    #+#             */
/*   Updated: 2018/11/13 22:02:22 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*tab;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	tab = ft_strdup(s);
	if (tab == NULL)
		return (NULL);
	while (tab[i])
	{
		tab[i] = (*f)(i, tab[i]);
		i++;
	}
	return (tab);
}
