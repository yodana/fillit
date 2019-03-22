/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:16:45 by yodana            #+#    #+#             */
/*   Updated: 2019/03/21 23:38:18 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		ft_calc_x(char *piece)
{
	int i;
	int x_max;
	int tmp;
	
	tmp = 0;
	x_max = 0;
	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			x_max++;
			while ((i + 1) % 4 != 0)
				i++;
		}
		i++;
	}
	printf("taille x de la piece == %d\n",x_max);
	return (x_max);
}

int		ft_calc_y(char *piece)
{
	int i;
	int y_max;
	int y_min;
	int tmp;
	tmp = 0;
	y_min = 0;
	y_max = 0;
	i = 0;
	printf("piece %s\n",piece);
	while(piece[i])
	{
		if (piece[i] == '#')
		{
			if (y_min > i % 4 || i < 5)
				y_min = i % 4;
			printf("y_min == %d\n",y_min);
			while (piece[i] == '#' && ((i + 1) % 5 != 0))
			{
				i++;
				tmp++;
			}
			
			if (tmp > y_max)
			{
				y_max = tmp;
			}
			tmp = -1;
			while ((i + 1) % 4 != 0)
				i++;
		}
		tmp++;
		i++;
	}
	printf("y+max == %d || y_min == %d || taille y == %d\n",y_max,y_min,y_max - y_min);
	return (y_max - y_min);
}

int		ft_points(char *piece)
{
	int points;
	int tab[2];
	int y;
	int j;

	y = 0;
	j = 0;
	points = 0;
	tab[0] = -1;
	tab[1] = -1;
	printf("piece == %s\n",piece);
	while (piece[j])
	{
		if (piece[j] == '#')
		{
			if (tab[0] == -1 || points < tab[y - 1])
			{
				tab[y] = points % 4;
				if (y == 0)
					y++;
			}
			while ((j + 1) % 4 != 0)
				j++;
			points = -1;
		}
		j++;
		points++;
	}
	printf("tab[0] == %d || tab[1] == %d\n",tab[0],tab[1]);
	if (tab[0] - tab[1] >= 3 || tab[1] == -1)
		return (0);
		return(tab[0] - tab[1]);
}

char	*ft_new_piece(char *piece, int points,int blocks)
{
	int i;
	char *new;
	int j;

	j = 0;
	new = (char*)malloc(sizeof(char) * 100);
	i = 0;
	while (piece[i] == '.')
		i++;
	while (blocks < 4)
	{
		if (piece[i] == '#')
			blocks++;
		new[j] = piece[i];
		j++;
		i++;
	}
	new[j] = piece[i];
	while (points > 0)
	{
		points--;
		new[j] = '.';
		j++;
	}
	new[j] = '\0';
	return (ft_strrev(new));
}

char	*ft_piece(char *piece)
{
	int points;
	char *new;
	int i;

	i = 0;
	points = ft_points(piece);
	new = ft_new_piece(ft_strrev(piece), points, 0);
	return (new);
}
