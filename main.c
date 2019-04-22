/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
/*   Updated: 2019/04/12 18:35:16 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

char			**ft_stock_map(int fd, char **map, int i, int j)
{
	int			ret;
	char		buf[400];
	int			k;
/*	while ((get_next_line(fd, &l)) > 0)
	{
		i++;
		(ft_check_gnl(l) == -1) ? ft_error() : 0;
		free(l);
	}
	close(fd);
	if (!(map = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	fd = open(arv, O_RDONLY);
	while ((get_next_line(fd, &l)) > 0)
	{
		map[i] = ft_strdup(l);
		free(l);
		i++;
	}
	close(fd);
	map[i] = NULL;*/
//	i = ft_check_file(argv, 0);
	k = 0;
	i = 0;
	while ((ret = read(fd, buf, 400)) > 0)
	{
		buf[ret] = '\0';
		while (buf[j])
		{
			if (buf[j] == '\n')
				k++;
			j++;
		}
		if (!(map = (char**)malloc(sizeof(char*) * (k + 2))))
			return (NULL);
		j = 0;
		k = 0;
		while (buf[j])
		{
			if (buf[j] == '\n' && buf[j - 1] == '\n')
			{
				map[i] = ft_strsub(buf, k, 0);
				k = k + 1;
				i++;
			}
			else if (buf[j] == '\n' || buf[j] == '\0')
			{
				map[i] = ft_strsub(buf, k, 4);
				i++;
				k = j + 1;
			}
			j++;
		}
	}
	map[i] = NULL;
	return (map);
}

t_tetris		*ft_add_piece(char **map, int count)
{
	int			i;
	char		*tmp;
	t_tetris	*new;
	t_tetris	*piece;

	i = 0;
	tmp = ft_strnew(0);
	while (map[i])
	{
		tmp = ft_strjoin_fr(tmp, map[i], 1);
		if ((i + 1) % 5 == 0)
		{
			(i == 4) ? piece = ft_new_tetris(tmp, count++)
				: (new = ft_new_tetris(tmp, count++));
			(i > 4 && piece != NULL) ? ft_tetrisadd(&piece, new) : 0;
			tmp = ft_strnew(0);
		}
		i++;
	}
	(i == 4) ? piece = ft_new_tetris(tmp, count++)
		: (new = ft_new_tetris(tmp, count++));
	(i > 4 && piece != NULL) ? ft_tetrisadd(&piece, new) : 0;
	return (piece);
}

void			ft_start(t_tetris *piece)
{
	int			i;
	t_final_map *final_map;
	t_final_map *new;

	i = 1;
	while (ft_tetris_count(piece) * 4 > i * i)
		i++;
	if (!(final_map = ft_new_map(i)))
		return ;
	while (ft_resolv(final_map, piece) != 1)
	{
		i++;
		if (!(new = ft_new_map(i)))
			return ;
		ft_final_map_fr(final_map);
		final_map = new;
	}
	ft_print(final_map->y, final_map->sol);
	ft_final_map_fr(final_map);
}

void			ft_print(int y, char **sol)
{
	int			i;

	i = 0;
	while (i < y)
	{
		ft_putstr(sol[i]);
		ft_putchar('\n');
		i++;
	}
}

int				main(int argc, char **argv)
{
	char		**map;
	int			fd;
	t_tetris	*piece;

	map = NULL;
	(argc != 2) ? ft_putendl("usage: ./fillit tetris_file") : 0;
	((fd = open(argv[1], O_RDONLY)) < 0) ? ft_error() : 0;
	if ((map = ft_stock_map(fd, map, 0, 0)) && argc == 2)
	{
		ft_check_line(map, 0, 0);
		piece = ft_add_piece(map, 0);
		if (piece == NULL)
		{
			close(fd);
			ft_piece_fr(piece);
			return (0);
		}
		ft_start(piece);
		ft_piece_fr(piece);
	}
	ft_strrdel(map);
	close(fd);
	return (0);
}
