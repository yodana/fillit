/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/03/11 20:31:47 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_point(char *piece)
{
	int i = 0;

	while (piece[i] != '#')
		i++;
	return (i);
}

char	**ft_tmp(char **sol)
{
	char **tmp;
	int i;

	i = 0;
	tmp = (char**)malloc(sizeof(char) * 100);
	while (sol[i])
	{
		tmp[i] = ft_strdup(sol[i]);
		i++;
	}
	return (tmp);
}

void	ft_calc_x_y(int points, int *y, int *x,int y_max)
{
	if (points > 0)
		*y = *y + points - (5 - y_max);
	if (((*y % y_max) == 0 && *y != 0) || *y > y_max - 1)
	{
		if (*y > y_max - 1)
			*y = *y % y_max;
		else
			*y = 0;
		*x = *x + 1;
	}
}

char	**ft_put_piece(char **sol, char *piece, int x, int y, int y_max)
{
	int i;
	char **tmp;
	tmp = ft_tmp(sol);
	i = 0;
	int points;

	points = 0;
	while (tmp[x] && piece[i])
	{
		if (tmp[x][y] == '#' && piece[i] == '#')
			return (NULL);
		if (piece[i] == '#')
			tmp[x][y] = '#';
		y++;
		if (i > 1 && (points = ft_point(&(piece[i]))) > 0)
			i = i + points - 1;
		i++;
		//printf("i = %d && points = %d\n",i,points);
		ft_calc_x_y(points, &y, &x,y_max);
	}
	return (tmp);
}

void	ft_resolv(t_final_map *final_map, t_tetris *piece, int x, int y)
{
	char **sol = final_map->sol;
	char *tetris = piece->map;
	if (x == final_map->x)
	{
		t_final_map *new = ft_new_map((final_map->x) + 1,(final_map->y) + 1);
		ft_resolv(new, piece, 0, 0);
	}
	if (sol[x][y] == '#' && y < final_map->y)
		ft_resolv(final_map, piece, x, y + 1);
	else if (y == final_map->y)
		ft_resolv(final_map, piece, x + 1, 0);
	else
	{
		if (ft_put_piece(sol,tetris, x, y, final_map->y) != NULL)
		{
			sol = ft_put_piece(sol, tetris,x, y,final_map->y);
			final_map->sol = sol;
		}	
		else
			ft_resolv(final_map, piece, x , y + 1);
			if (piece->next)
			ft_resolv(final_map, piece->next,x, y);
	}
	x = 0;
	while (x < final_map->y)
	{
		printf("%s\n",sol[x]);
		x++;
	}
	ft_putchar('\n');
}
