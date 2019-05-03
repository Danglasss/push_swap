/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:46:52 by damboule          #+#    #+#             */
/*   Updated: 2018/11/13 22:31:54 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*tab;

	i = 0;
	tab = (unsigned char*)b;
	while (len-- > 0)
		tab[i++] = (unsigned char)c;
	b = (void*)tab;
	return (b);
}
