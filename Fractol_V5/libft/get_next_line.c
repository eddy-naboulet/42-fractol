/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enaboule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:55:34 by enaboule          #+#    #+#             */
/*   Updated: 2016/03/29 11:19:26 by enaboule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	if ((str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
						+ 1))) == NULL)
		return (NULL);
	str = ft_strcpy(str, s1);
	ft_strcpy(str + ft_strlen(s1), s2);
	free(s1);
	return (str);
}

int		ft_g_error(char **gnl, char **line)
{
	if (*gnl != NULL && ft_strlen(*gnl) != 0)
	{
		*line = ft_strdup(*gnl);
		free(*gnl);
		*gnl = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char		*gnl = NULL;
	char			buf[BUF_SIZE + 1];
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	while (gnl == NULL || ft_strchr(gnl, '\n') == NULL)
	{
		if ((ret = read(fd, buf, BUF_SIZE)) == -1)
			return (-1);
		if (ret == 0)
			return (ft_g_error(&gnl, line));
		buf[ret] = '\0';
		if (gnl == NULL)
			gnl = ft_strdup(buf);
		else
			gnl = ft_strjoin_gnl(gnl, buf);
	}
	*line = ft_strsub(gnl, 0, ft_strchr(gnl, '\n') - gnl);
	gnl = ft_strsub(gnl, ft_strchr(gnl, '\n') - gnl + 1,
			ft_strlen(ft_strchr(gnl, '\n') + 1));
	return (1);
}
