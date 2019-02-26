/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/02/26 23:30:07 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**ft_put_piece(char **sol, char **piece, int x, int y)
{
	int x_t = 0;
	int y_t = 0;

	while (piece[x_t][y_t] != '#')
	{
		y_t++;
		if (!(piece[x_t][y_t]))
		{
			y_t = 0;
			x_t++;
		}
	}
	while (piece[x_t])
	{
		while (piece[x_t][y_t] && sol[x][y])
		{
			if (piece[x_t][y_t] == '#' && sol[x][y] == '.')
				sol[x][y] = '#';
			if (piece[x_t][y_t] == '#' && sol[x][y] == '#')
			{
				printf("lol");
				return (NULL);
			}
			y_t++;
			y++;
		}
		if (piece[x_t][y_t] == '\0')
		{
			y_t = 0;
			x_t++;
		}
		if (sol[x][y] == '\0')
		{
			y = 0;
			x++;
		}
	}
	return (sol);

}
void	ft_resolv(t_final_map *final_map, t_tetris *piece, int x, int y)
{
	char **sol = final_map->sol;
	char **tetris = piece->map;

	if (sol[x][y] == '#' && y < 4)
			ft_resolv(final_map, piece, x, y + 1);
	if (sol[x][y] == '#' && y >= 4)
		ft_resolv(final_map, piece, x + 1, 0);
	//int x_t = 0;
	//int y_t = 0;
	if ((sol = ft_put_piece(sol,tetris, x, y)) != NULL)
	{
		if (piece->next)
			ft_resolv(final_map, piece->next, 0, 0);
	}
	else
		ft_resolv(final_map, piece, x , y + 1);
		x = 0;
		while (x < 4)
		{
			printf("%s\n",((char**)final_map->sol)[x]);
			x++;
		}
	x = 0;
		y = 0;
	//}
}
