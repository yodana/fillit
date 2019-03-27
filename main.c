/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
/*   Updated: 2019/03/27 18:43:26 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

char	**ft_stock_map(char *argv, char *line, char **map)
{
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	close(fd);
	if (!(map = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

t_tetris	*ft_add_piece(char **map, int count)
{
	int			i;
	char		*tmp;
	t_tetris	*new;
	t_tetris	*piece;

	i = 0;
	tmp = ft_strnew(0);
	while (map[i])
	{
		tmp = ft_strjoin_fr(tmp, map[i],  1);
		if ((i + 1) % 5 == 0)
		{
			if (i == 4)
				piece = ft_new_tetris(tmp, count++);
			else
			{
				new = ft_new_tetris(tmp,count++);
				ft_tetrisadd(&piece, new);
			}
			tmp = ft_strnew(0);
		}
		i++;
	}
	if (i == 4)
		piece = ft_new_tetris(tmp, count++);
	else
	{
		new = ft_new_tetris(tmp, count++);
		ft_tetrisadd(&piece, new);
	}
	return (piece);
}

void		ft_start(t_tetris *piece)
{
	int i;
	t_final_map *final_map;
	t_final_map *new;

	i = 1;
	while (ft_tetris_count(piece) * 4 > i * i)
		i++;
	final_map = ft_new_map(i);
	while (ft_resolv(final_map, piece) != 1)
	{
		i++;
		new = ft_new_map(i);
		ft_final_map_fr(final_map);
		final_map = new;
	}
	ft_print(final_map->y, final_map->sol);
	ft_final_map_fr(final_map);
}

void		ft_print(int y, char **sol)
{
	int i;

	i = 0;
	while (i < y)
	{
		ft_putstr(sol[i]);
		ft_putchar('\n');
		i++;
	}
}

int			main(int argc, char **argv)
{
	char **map;
	char *line;
	t_tetris *piece;

	line = NULL;
	map = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetris_file");
		return (0);
	}
	if ((map = ft_stock_map(argv[1], line, map)))
	{
		ft_check_line(map, 0, 0);
		piece = ft_add_piece(map, 0);
		ft_start(piece);
		ft_piece_fr(piece);
		ft_strrdel(map);
	}
	return (0);
}
