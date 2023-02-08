/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwhana21 <iwhana21@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 17:29:49 by gkord             #+#    #+#             */
/*   Updated: 2022/06/04 04:40:57 by iwhana21         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_history(t_minishell *data)
{
	int		history_slider;
	int		fd;
	char	*line;

	history_slider = 0;
	fd = open(data->file_history, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		free(line);
		history_slider++;
	}
	free(line);
	close(fd);
	return (history_slider);
}

int	definition_history_line2(t_minishell *data, int *i)
{
	data->term->str = (char *)malloc(sizeof(char) * 101);
	if (data->term->str == NULL)
		return (0);
	*i = 0;
	write(1, "> ", 2);
	tputs(save_cursor, 1, ft_putchar);
	return (0);
}

int	definition_history_line(t_minishell *data, int *i)
{
	data->term->history_slider = ft_strlen_history(data);
	data->term->str = (char *)malloc(sizeof(char) * 101);
	if (data->term->str == NULL)
		return (0);
	*i = 0;
	write(1, "minishell$ ", 11);
	tputs(save_cursor, 1, ft_putchar);
	return (0);
}

char	*reader_history_line(t_minishell *data, int history_slider)
{
	char	*history_line;
	int		fd;
	int		i;

	i = 0;
	fd = open(data->file_history, O_RDONLY);
	while (i != history_slider)
	{
		get_next_line(fd, &history_line);
		free(history_line);
		i++;
	}
	get_next_line(fd, &history_line);
	close(fd);
	return (history_line);
}

int	crete_or_cheak_file_history(t_minishell *data, int lvl)
{
	char	*path;
	int		fd;
	char	*tmp;
	char	*itoa;

	path = getenv("PWD");
	path = ft_strjoin(path, "/tmp/lvl");
	tmp = path;
	itoa = ft_itoa(lvl);
	path = ft_strjoin(path, itoa);
	free(tmp);
	free(itoa);
	fd = open(path, O_WRONLY | O_CREAT, 0777 | O_TRUNC | O_APPEND);
	if (fd == -1)
		return (-1);
	data->file_history = path;
	close(fd);
	return (0);
}
