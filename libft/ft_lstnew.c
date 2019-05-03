/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:46:46 by damboule          #+#    #+#             */
/*   Updated: 2018/11/29 19:03:26 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*temp;

	temp = (t_list*)malloc(sizeof(t_list *));
	if (temp == NULL)
		return (NULL);
	if (temp && content)
	{
		temp->content = (t_list*)malloc(sizeof(t_list));
		ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
		temp->next = NULL;
	}
	else if (temp)
	{
		temp->content = NULL;
		temp->content_size = content_size;
		temp->next = NULL;
	}
	return (temp);
}
