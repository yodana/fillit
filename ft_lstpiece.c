/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:21:24 by yodana            #+#    #+#             */
/*   Updated: 2019/03/11 19:57:33 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>
t_final_map	*ft_new_map(int new_x, int new_y)
{
	t_final_map *new;
	char **map;
	int x;
	int y;

	x = 0;
	y = 0;
	map = (char**)malloc(sizeof(char*) * 33);
	map[x] = ft_strnew(0);
	while (x < new_x)
	{
		while (y < new_y)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		y = 0;
		x++;
		map[x] = ft_strnew(4);
	}
	map[x] = NULL;
	new = malloc(sizeof(t_final_map));
	new->next = NULL;
	new->x = new_x;
	new->y = new_y;
	new->sol = map;
	return (new);
}

t_tetris	*ft_new_tetris()
{
	t_tetris *new;

	new = malloc(sizeof(t_tetris));
	new->next = NULL;
	new->map = (char*)malloc(sizeof(char) * 33);
	return (new);
}
