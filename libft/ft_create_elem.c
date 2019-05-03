/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 11:28:30 by damboule          #+#    #+#             */
/*   Updated: 2018/11/29 15:44:59 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_create_elem(t_list **new, char *data)
{
	(*new) = (t_list*)malloc(sizeof(t_list));
	(*new)->content_size = 0;
	(*new)->content = (void*)data;
	(*new)->next = NULL;
}
