/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:42:38 by damboule          #+#    #+#             */
/*   Updated: 2018/11/25 08:52:28 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int	i;

	i = 0;
	if (!(*f))
		return ;
	if (!(s))
		return ;
	while (s[i])
	{
		(*f)(&s[i]);
		i++;
	}
}
