/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:44:36 by damboule          #+#    #+#             */
/*   Updated: 2018/11/21 15:42:11 by damboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_end(char const *s)
{
	int	i;
	int len;

	i = ft_strlen(s) - 1;
	len = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	&& i >= 0)
	{
		i--;
		len++;
	}
	return (len);
}

static int	ft_start(char const *s)
{
	int	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	&& s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;

	if (!s)
		return (0);
	start = ft_start(s);
	end = ft_end(s);
	len = ft_strlen(s) - (start + end);
	if (start == 0 && len == 0)
		return (ft_strdup(s));
	if (start == (int)ft_strlen(s))
		return (ft_strsub(s, 0, 0));
	return (ft_strsub(s, start, len));
}
