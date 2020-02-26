/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <joserabasot@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 06:25:30 by jperez-r          #+#    #+#             */
/*   Updated: 2020/02/26 06:44:23 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	put_line(char **line, char **aux)
{
	char	*tmp;
	int		pos;

	if ((pos = ft_strchr(*aux, '\n')) >= 0)
	{
		*line = ft_substr(*aux, 0, pos);
		tmp = ft_substr(*aux, pos + 1, ft_strlen(*aux));
		free(*aux);
		*aux = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(*aux);
		free(*aux);
		*aux = NULL;
		return (0);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*aux[4096];
	char		*buff;
	int			reader;
	int			ctrl;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buff = malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!aux[fd])
		aux[fd] = ft_strdup("");
	while (ft_strchr(aux[fd], '\n') == -1
			&& (reader = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[reader] = '\0';
		aux[fd] = ft_strjoin(aux[fd], buff);
	}
	if (reader == -1)
		ctrl = -1;
	else
		ctrl = put_line(line, &aux[fd]);
	free(buff);
	return (ctrl);
}
