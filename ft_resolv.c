/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/03/27 11:10:12 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_put_check(t_final_map *final_map, t_tetris *piece, int x, int y)
{
	int		i;
	int		points;
	char	*tetris;
	char	**sol;

	sol = final_map->sol;
	tetris = piece->map;
	points = 0;
	i = 0;
	if (sol[x][y - 1] && sol[x][y - 1] == '#')
	{
		while (tetris[i] != '#')
			i++;
	}
	while (tetris[i])
	{
		if ((sol[x][y] >= 65 && sol[x][y] <= 90) && tetris[i] == '#')
			return (0);
		y++;
		if (i > 1 && (points = ft_point(&(tetris[i]))) > 0)
			i = i + points - 1;
		i++;
		ft_calc_x_y(points, &y, &x, final_map->y);
	}
	return (1);
}

char	**ft_put_piece(t_final_map *final_map, t_tetris *piece, int x, int y)
{
	int		i;
	int		points;
	char	**sol;
	char	*tetris;

	tetris = piece->map;
	i = 0;
	points = 0;
	sol = final_map->sol;
	if (sol[x][y - 1] && sol[x][y - 1] == '#')
	{
		while (tetris[i] != '#')
			i++;
	}
	while (tetris[i])
	{
		if (tetris[i] == '#')
			sol[x][y] = piece->lettre;
		y++;
		if (i > 1 && (points = ft_point(&(tetris[i]))) > 0)
			i = i + points - 1;
		i++;
		ft_calc_x_y(points, &y, &x, final_map->y);
	}
	return (sol);
}

char	**ft_remove_piece(t_final_map *final_map, t_tetris *piece, int x, int y)
{
	int		i;
	int		points;
	char	*tetris;
	char	**sol;

	sol = final_map->sol;
	i = 0;
	points = 0;
	tetris = piece->map;
	if (sol[x][y - 1] && sol[x][y - 1] == '#')
	{
		while (tetris[i] != '#')
			i++;
	}
	while (tetris[i])
	{
		if (tetris[i] == '#')
			sol[x][y] = '.';
		y++;
		if (i > 1 && (points = ft_point(&(tetris[i]))) > 0)
			i = i + points - 1;
		i++;
		ft_calc_x_y(points, &y, &x, final_map->y);
	}
	return (sol);
}

int		ft_resolv(t_final_map *final_map, t_tetris *piece)
{
	int x;
	int y;

	if (piece == NULL)
		return (1);
	x = 0;
	y = 0;
	while (x < final_map->y - piece->x_max + 1)
	{
		while (y < final_map->y - piece->y_max + 1)
		{
			if ((ft_put_check(final_map, piece, x, y) > 0))
			{
				final_map->sol = ft_put_piece(final_map, piece, x, y);
				if (ft_resolv(final_map, piece->next))
					return (1);
				else
					final_map->sol = ft_remove_piece(final_map, piece, x, y);
			}
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}
