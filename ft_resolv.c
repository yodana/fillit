/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:58:50 by yodana            #+#    #+#             */
/*   Updated: 2019/02/21 16:33:18 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
void	ft_resolv(t_final_map *final_map, t_tetris **piece, int x, int y)
{
	t_tetris *tmp;
	tmp = *piece;
	while(tmp)
	{
		printf("lol");
		tmp = tmp->next;
	}
	char **tetris = tmp->map;
	char **sol = final_map->sol;
	int x_t = 0;
	int y_t = 0;
	//if(sol[x][y] == '.')
	//{
		while(tetris[x_t])
		{
	//		printf("%s\n",tetris[x_t]);
			while (tetris[x_t][y_t])
			{
				if (tetris[x_t][y_t] == '#' && sol[x][y] != '#')
					sol[x][y] = '#';
				y_t++;
				y++;
			}
			y_t = 0;
			y = 0;
			x_t++;
		//	printf("%s\n",sol[x]);
			x++;
		}
		final_map->sol = sol;
		piece = &tmp;
	//	if(tmp->next)	
	//		ft_resolv(final_map,&(tmp->next), 0, 0);
		x = 0;
		/*while (x < 4)
		{
			printf("%s\n",sol[x]);
			x++;
		}*/
	//}
}
