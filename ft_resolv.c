/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/02/18 19:43:13 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_resolv(t_tetris **piece, int x, int y)
{
	while (piece->next)
	{
		while(x < 4 && y < 4)
		{
			while (y < final_map->xmax)
			{
				while (y < 4)
				{
					if(piece->map[x][y] == "#")
						map[x][y] == "#";
					ft_resolv(piece, x+ 1, y);
				}
				ft_resolv(piece,0,y+1);
			}

		}
