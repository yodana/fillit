/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/03/19 04:54:24 by yodana           ###   ########.fr       */
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
	int blocks = 0;
	if (tmp[x][y - 1] && tmp[x][y - 1] == '#')
	{
		while (piece[i] != '#')
			i++;
	}
	while (tmp[x] && piece[i])
	{
		if (tmp[x][y] == '#' && piece[i] == '#')
			return (NULL);
		if (piece[i] == '#')
		{
			tmp[x][y] = '#';
			blocks++;
		}
		y++;
		if (i > 1 && (points = ft_point(&(piece[i]))) > 0)
			i = i + points - 1;
		i++;
		ft_calc_x_y(points, &y, &x,y_max);
	}
	if (blocks != 4)
		return (NULL);
	return (tmp);
}

void	ft_print(int y, char **sol)
{
	int i;
	i = 0;
	while (i < y)
	{
		printf("%s\n", sol[i]);
		i++;
	}
	ft_putchar('\n');
}

char	**ft_remove_piece(char **sol, char *piece, int x, int y,int y_max)
{
		int i;
	char **tmp;
	tmp = ft_tmp(sol);
	i = 0;
	int points;
	points = 0;
	int blocks = 0;
	if (tmp[x][y - 1] && tmp[x][y - 1] == '.')
	{
		while (piece[i] != '#')
			i++;
	}
	/*while (tmp[x] && piece[i])
	{
		if (tmp[x][y] == '#' && piece[i] == '#')
			return (NULL);
		if (piece[i] == '#')
		{
			tmp[x][y] = '.';
			blocks++;
		}
		y++;
		if (i > 1 && (points = ft_point(&(piece[i]))) > 0)
			i = i + points - 1;
		i++;
		ft_calc_x_y(points, &y, &x,y_max);
	}*/
	y_max = 0;
	if (blocks != 4)
		return (NULL);
	return (tmp);
}

int		ft_resolv(t_final_map *final_map, t_tetris *piece, int x, int y, t_tetris *begin)
{
	//printf("coucou\n");
	if (piece == NULL)
	{
		return (1);
	}
	char **sol = final_map->sol;
	char *tetris = piece->map;
	//int b = 1;
	//char **tmp = ft_tmp(sol);
	//static char **save = NULL;
	while ((final_map->x - x - piece->x_max + 1) > 0)
	{
		while((final_map->y - y - piece->y_max + 1) > 0)
		{
		if (ft_put_piece(sol, tetris, x, y , final_map->y) != NULL)
		{
			sol = ft_put_piece(sol, tetris, x, y, final_map->y);
			ft_print(final_map->y, sol);
			final_map->sol = sol;
			if (ft_resolv(final_map, piece->next, 0, 0, begin))
			{
				printf("salut fdp\n");
				return (1);
			}
			else
			{
				printf("dans else ==\n");
				ft_print(final_map->y,sol);
				sol = ft_remove_piece(sol, tetris, x, y,final_map->y);
				ft_print(final_map->y,sol);
			}
		}
		y++;
		}
		y = 0;
		x++;
	}
	return (0);
	/*if (x == final_map->x)
	{
		if(piece  == NULL)
			return ;
		t_final_map *new = ft_new_map((final_map->x) + 1);
		ft_resolv(new, begin, 0, 0,begin);
	}
	else if (sol[x][y] == '#' && y < final_map->y)
		ft_resolv(final_map, piece, x, y + 1,begin);
	else if (y == final_map->y)
		ft_resolv(final_map, piece, x + 1, 0,begin);
	else
	{
		if ((final_map->y - y - piece->y_max + 1) >= 0 && ft_put_piece(sol,tetris, x, y, final_map->y) != NULL)
		{
			sol = ft_put_piece(sol, tetris,x, y,final_map->y);
			final_map->sol = sol;
		}
		else
		{
			ft_resolv(final_map, piece, x , y + 1,begin);
			return ;
		}
		if (piece->next)
			ft_resolv(final_map, piece->next,x, y,begin);
	}
	x = 0;
	while (x < final_map->x)
	{
		printf("%s\n",sol[x]);
		x++;
	}
	ft_putchar('\n');
*/}
