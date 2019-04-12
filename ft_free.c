/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 03:13:22 by yodana            #+#    #+#             */
/*   Updated: 2019/04/12 18:28:58 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_file(char *argv, int ret)
{
	int		fd;
	char	buf[5];
	int		i;

	i = 0;
	fd = open(argv, O_RDONLY);
	while ((ret = read(fd, buf, 5)) > 0)
	{
		buf[ret] = '\0';
		if (ft_check_l(buf) == -1)
		{
			close(fd);
			ft_error();
		}
		if (ft_strchr(buf, '\n'))
			i++;
	}
	close(fd);
	if (ret == -1)
		ft_error();
	i++;
	return (i);
}

int		ft_check_l(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#' && line[i] != '\n')
			return (-1);
		i++;
	}
	return (0);
}

void	ft_final_map_fr(t_final_map *final_map)
{
	ft_strrdel(final_map->sol);
	free(final_map);
}

void	ft_piece_fr(t_tetris *piece)
{
	t_tetris *tmp;

	while (piece)
	{
		ft_strdel(&(piece->map));
		tmp = piece->next;
		free(piece);
		piece = tmp;
	}
}
