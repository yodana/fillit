/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/02/28 22:48:04 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
char	**ft_new_sol(char **sol)
{
	char **new;
	int i = 0;
	int j = 0;
	new = (char**)malloc(sizeof(char) * 33);
	new[j] = ft_strnew(0);
	while (j < 5)
	{
		while (i < 5)
		{
			new[j][i] = sol[j][i];
			i++;
		}
		new[j][i] = '.';
		i++;
		new[j][i] = '\0';
		i = 0;
		j++;
	}
	return (new);
}

char	**ft_put_piece(char **sol, char *piece, int x, int y)
{
	int		x_t;
	char	**tmp;
	int		b;
	int		c;
	int blocks = 0;
	b = y;
	c = x;
	x_t = 0;
	tmp = sol;
	int i = 0;
	tmp = ((char**)malloc(sizeof(char) * 10000));
	tmp[i] = ft_strnew(0);
	while (sol[i])
	{
		tmp[i] = ft_strdup(sol[i]);
		printf("before %s\n",tmp[i]);
		i++;
	}
	printf("x == %d | y == %d\n",x,y);
	while(piece[x_t] != '#')
		x_t++;
	while (piece[x_t])
	{
		if (piece[x_t] == '#' && tmp[x][y] != '#' && tmp[x][y])
		{
			blocks++;
			tmp[x][y] = '#';
		}
		y++;
		x_t++;
		if (x_t % 4 == 0)
		{
			x++;
			y = b;
			while (piece[x_t] && piece[x_t] == '.')
				x_t++;
		}
	}
	printf("blocks = %d\n",blocks);
	if (blocks != 4)
		return (NULL);
	i = 0;
	while (tmp[i])
	{
		printf("after %s\n",tmp[i]);
		i++;
	}
	ft_putchar('\n');
	return (tmp);
}

void	ft_resolv(t_final_map *final_map, t_tetris *piece, int x, int y)
{
	char **sol = final_map->sol;
	char *tetris = piece->map;
	if (x == final_map->x)
	{
		t_final_map *new = ft_new_map(sol,(final_map->x) + 1,(final_map->y) + 1);
		ft_resolv(new, piece, 0, 0);
	}
	if (sol[x][y] == '#' && y < final_map->y)
		ft_resolv(final_map, piece, x, y + 1);
	else if (y == final_map->y)
		ft_resolv(final_map, piece, x + 1, 0);
	else
	{
		if (ft_put_piece(sol,tetris, x, y) != NULL)
		{
			sol = ft_put_piece(sol, tetris,x, y);
			final_map->sol = sol;
			if (piece->next)
				ft_resolv(final_map, piece->next,x, y);
		}
		else
			ft_resolv(final_map,piece,x, y + 1);
	}
	x = 0;
	while (x < final_map->x)
	{
		printf("%s\n",sol[x]);
		x++;
	}
	ft_putchar('\n');
}
