/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:08:35 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/04/28 17:08:37 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

static int	start_prepare_processing(char **line, char **start, char *ptr_nl)
{
	*ptr_nl = '\0';
	*line = ft_strdup(*start);
	if (!(*line))
		return (-1);
	ptr_nl++;
	ft_strlcpy(*start, ptr_nl, ft_strlen(ptr_nl) + 1);
	if (!(*start))
		return (-1);
	return (1);
}

static int	start_prepare(char **start, char **line)
{
	char	*ptr_nl;

	if (*start)
	{
		ptr_nl = ft_strchr(*start, '\n');
		if (ptr_nl)
			return (start_prepare_processing(line, start, ptr_nl));
		*line = ft_strdup(*start);
		if (!(*line))
			return (-1);
		free(*start);
		*start = NULL;
	}
	else
	{
		*line = malloc(sizeof(char));
		if (!(*line))
			return (-1);
		**line = '\0';
	}
	return (0);
}

static int	line_out(char **line, char **start, char *ptr_nl, char *buff)
{
	char	*tmp;

	*ptr_nl = '\0';
	tmp = *line;
	*line = ft_strjoin(*line, buff);
	if (!(*line))
		return (-1);
	free(tmp);
	*start = ft_strdup(++ptr_nl);
	if (!(*start))
		return (-1);
	free(buff);
	return (1);
}

static int	pr_get_next_line(int fd, char **line, char **buff, char **start)
{
	int	qnty_els;

	*buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !*buff || fd > 19)
	{
		if (*buff)
			free(*buff);
		return (-1);
	}
	qnty_els = start_prepare(start, line);
	if (qnty_els == 1)
	{
		free(*buff);
		return (1);
	}
	if (qnty_els == -1)
	{
		free(*buff);
		return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	long		qnty_els;
	char		*ptr_nl;
	char		*tmp;
	static char	*start;

	qnty_els = pr_get_next_line(fd, line, &buff, &start);
	if (qnty_els == 1 || qnty_els == -1)
		return (qnty_els);
	qnty_els = read(fd, buff, BUFFER_SIZE);
	while (qnty_els)
	{
		buff[qnty_els] = '\0';
		ptr_nl = ft_strchr(buff, '\n');
		if (ptr_nl)
			return (line_out(line, &start, ptr_nl, buff));
		tmp = *line;
		*line = ft_strjoin(*line, buff);
		free(tmp);
		if (!(*line))
			return (-1);
		qnty_els = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (0);
}
