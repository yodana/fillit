/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:21:24 by yodana            #+#    #+#             */
/*   Updated: 2019/03/19 04:49:25 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

int			ft_tetris_count(t_tetris *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char		**ft_clean_map(int side, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(map = (char**)malloc(sizeof(char*) * side + 1)))
		return (NULL);
	map[x] = ft_strnew(0);
	while (x < side)
	{
		while (y < side)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		y = 0;
		x++;
		map[x] = ft_strnew(side);
	}
	map[x] = NULL;
	return (map);
}

t_final_map	*ft_new_map(int side)
{
	t_final_map *new;
	char **map;

	map = NULL;
	map = ft_clean_map(side, map);
	if (!(new = (t_final_map*)malloc(sizeof(t_final_map))))
		return (NULL);
	new->next = NULL;
	new->x = side;
	new->y = side;
	new->sol = map;
	return (new);
}

t_tetris	*ft_new_tetris(char *map)
{
	t_tetris *new;

	if (!(new = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	new->y_max = ft_calc_y(map);
	new->x_max = ft_calc_x(map);
	new->map = ft_strdup(ft_piece(map));
	new->next = NULL;
	return (new);
}
