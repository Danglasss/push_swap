/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:45:26 by damboule          #+#    #+#             */
/*   Updated: 2018/11/20 21:48:17 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *temp;

	temp = (void*)malloc(sizeof(void*) * size);
	if (temp == NULL)
		return (NULL);
	else
		return (ft_memset(temp, 0, size));
	return (0);
}
