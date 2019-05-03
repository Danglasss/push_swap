/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 22:20:33 by damboule          #+#    #+#             */
/*   Updated: 2018/11/30 12:35:07 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_create_list(char *data, size_t len)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(t_list));
	new->content_size = len;
	new->content = (void*)data;
	new->next = NULL;
	return (new);
}
