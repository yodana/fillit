/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/03/21 03:19:41 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_point(char *piece)
{
	int i = 0;

	while (piece[i] != '#' || (piece[i] >= 65 && piece[i] <= 90))
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

char	**ft_put_piece(char **sol, t_tetris *piece, int x, int y, int y_max)
{
	int i;
	char **tmp;
	tmp = ft_tmp(sol);
	i = 0;
	int points;
	points = 0;
	int blocks = 0;
	char *tetris = piece->map;
	if (tmp[x][y - 1] && tmp[x][y - 1] == '#')
	{
		while (tetris[i] != '#')
			i++;
	}
	while (tetris[i])
	{
		if ((tmp[x][y] >= 65 && tmp[x][y] <= 90) && tetris[i] == '#')
		{
			return (NULL);
		}
		if (tetris[i] == '#')
		{
			tmp[x][y] = piece->lettre;
			blocks++;
		}
		y++;
		if (i > 1 && (points = ft_point(&(tetris[i]))) > 0)
			i = i + points - 1;
		i++;
		ft_calc_x_y(points, &y, &x,y_max);
	}
	return (tmp);
}

char	**ft_remove_piece(char **sol, t_tetris *piece, int x, int y,int y_max)
{
		int i;
	char **tmp;
	tmp = ft_tmp(sol);
	i = 0;
	int points;
	points = 0;
	int blocks = 0;
	char *tetris = piece->map;
	if (tmp[x][y - 1] && tmp[x][y - 1] == '.')
	{
		while (tetris[i] != '#')
			i++;
	}
	while (tetris[i])
	{
		ft_print(y_max,tmp);
		if (tetris[i] == '#')
		{
			tmp[x][y] = '.';
			blocks++;
		}
		y++;
		if (i > 1 && (points = ft_point(&(tetris[i]))) > 0)
			i = i + points - 1;
		i++;
		ft_calc_x_y(points, &y, &x,y_max);
	}
	return (tmp);
}

int		ft_resolv(t_final_map *final_map, t_tetris *piece,int nbr_p, t_tetris *begin)
{
	ft_print(final_map->y, final_map->sol);
	if (piece == NULL)
		return (1);
	int x = 0;
	int y = 0;
	//int b = 1;
	//char **tmp = ft_tmp(sol);
	//static char **save = NULL;
	while (x < final_map->y - piece->x_max + 1)
	{
		while(y < final_map->y - piece->y_max + 1)
		{
		if (ft_put_piece(final_map->sol, piece, x, y , final_map->y) != NULL)
		{
			final_map->sol = ft_put_piece(final_map->sol, piece, x, y, final_map->y);
			//ft_print(final_map->y, final_map->sol);
			nbr_p++;
			//ft_print(final_map->y,final_map->sol);
			if (ft_resolv(final_map, piece->next,nbr_p,begin))
			{
				return (1);
			}
				//printf("dans else ==\n");
				//ft_print(final_map->y,sol);
			//else	
			//{
			//	final_map->sol = ft_remove_piece(final_map->sol, piece, x, y,final_map->y);
			//}
				//ft_print(final_map->y,sol);
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
