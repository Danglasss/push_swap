/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:33:05 by damboule          #+#    #+#             */
/*   Updated: 2018/11/30 16:07:19 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static t_list	*ft_check_static_list(t_list **react, int fd)
{
	t_list	*tmp;

	tmp = (*react);
	while (tmp != NULL)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	ft_lstadd(react, ft_create_list(NULL, (size_t)fd));
	return (*react);
}

static void		ft_push_line_stack(t_list **react, int *stance)
{
	char	*tmp;
	int		index;

	tmp = NULL;
	index = ft_strlen((*react)->content);
	tmp = ft_strsub((*react)->content, *stance + 1, index - (*stance - 1));
	free((*react)->content);
	(*react)->content = NULL;
	(*react)->content = ft_strdup_free(tmp);
}

static void		ft_push_line(t_list **react, int *stance, char **line)
{
	char	*tmp;
	int		index;

	tmp = NULL;
	if (((ft_chrlen((*react)->content, '\n') >= 1)))
	{
		index = ft_strchar((*react)->content, '\n');
		tmp = ft_strjoin_free_s1((*react)->content, *line);
		*line = ft_strsub(tmp, 0, index);
		(*react)->content = ft_strsub_free(tmp, index + 1,
		ft_strlen(tmp) - index);
		return ;
	}
	else if (*stance != (int)ft_strlen(*line) && *stance != -1
	&& ft_strlen(*line) != 0)
		tmp = ft_strsub(*line, *stance + 1, ft_strlen(*line) - (*stance - 1));
	if (*stance > 0 && ft_strlen(*line) != 0)
		*line = ft_strsub_free(*line, 0, *stance);
	if ((*react)->content != NULL)
		*line = ft_strncat_free_s2((*react)->content, *line, *stance);
	(*react)->content = NULL;
	free((*react)->content);
	(*react)->content = ft_strdup_free(tmp);
}

static	int		ft_take_line(char **line, int *stance, int *retention, int fd)
{
	char	buffer[BUFF_SIZE + 1];

	ft_bzero(buffer, BUFF_SIZE + 1);
	*line = NULL;
	while ((*retention = read(fd, buffer, BUFF_SIZE) > 0))
	{
		*line = ft_strjoin_free_s1(*line, buffer);
		if ((*stance = ft_strchar(*line, '\n')) != -1)
			return (*retention);
		ft_bzero(buffer, BUFF_SIZE + 1);
	}
	if (*stance == -1 && ft_strlen(*line) > 0)
		return (*retention = 1);
	return (*retention);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*react = NULL;
	int				stance;
	int				verify;
	int				ret;

	if (fd < 0 || read(fd, react, 0) < 0)
		return (-1);
	react = ft_check_static_list(&react, fd);
	ft_take_line(line, &stance, &ret, fd);
	verify = ft_chrlen(react->content, '\n');
	if (ret == -1 || (ret == 0 && verify < 1 &&
	ft_strlen(react->content) == 0))
		return (ret);
	else if (ret == 0 && verify >= 1)
	{
		stance = ft_strchar(react->content, '\n');
		*line = ft_strsub(react->content, 0, stance);
		ft_push_line_stack(&react, &stance);
		return (1);
	}
	ft_push_line(&react, &stance, line);
	return (1);
}
