/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/03/05 18:45:42 by yodana           ###   ########.fr       */
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
	int i;
	char **tmp;
	tmp = (char**)malloc(sizeof(char) * 100);
	i = 0;
	while (sol[i])
	{
		tmp[i] = ft_strnew(4);
		tmp[i] = ft_strdup(sol[i]);
		i++;
	}
	i = 0;
	while (piece[i])
	{
		tmp[x][y] = piece[i];
		y++;
		if ((i + 1) % 4 == 0)
		{
			y = 0;
			x++;
		}
		i++;
	}
	return (tmp);
}

void	ft_resolv(t_final_map *final_map, t_tetris *piece, int x, int y)
{
	char **sol = final_map->sol;
	char *tetris = piece->map;
	if (x == 4)
	{
		return ;
		//t_final_map *new = ft_new_map(sol,(final_map->x) + 1,(final_map->y) + 1);
		//ft_resolv(new, piece, 0, 0);
	}
	if (sol[x][y] == '#' && y < 4)
		ft_resolv(final_map, piece, x, y + 1);
	else if (y == 4)
		ft_resolv(final_map, piece, x + 1, 0);
	else
	{
		if (ft_put_piece(sol,tetris, x, y) != NULL)
		{
			printf("on passe\n");
			sol = ft_put_piece(sol, tetris,x, y);
			final_map->sol = sol;
		}	
		//else
		//§	ft_resolv(final_map, piece, x , y + 1);
		if (piece->next)
				ft_resolv(final_map, piece->next,x, y);
	}
	x = 0;
	while (x < 4 && y != 4)
	{
		printf("%s\n",sol[x]);
		x++;
	}
	ft_putchar('\n');
}
