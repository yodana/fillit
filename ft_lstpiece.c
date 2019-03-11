/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:21:24 by yodana            #+#    #+#             */
/*   Updated: 2019/03/11 19:18:27 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

char		**ft_clean_map(int side, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(map = (char**)malloc(sizeof(char*) * side)))
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

t_tetris	*ft_new_tetris()
{
	t_tetris *new;

	if (!(new = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	new->next = NULL;
	if (!(new->map = (char*)malloc(sizeof(char))))
		return (NULL);
	return (new);
}
