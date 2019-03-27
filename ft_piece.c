/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:16:45 by yodana            #+#    #+#             */
/*   Updated: 2019/03/27 20:03:29 by yodana           ###   ########.fr       */
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
	return (x_max);
}

int		ft_calc_y(char *piece)
{
	int i;
	int y_max;
	int y_min;

	y_min = 0;
	y_max = 0;
	i = 0;
	while (piece[i])
	{
		if (piece[i] == '#')
		{
			if (y_max == 0 && y_min == 0)
			{
				y_min = i % 4 + 1;
				y_max = i % 4 + 1;
			}
			if (i % 4 + 1 > y_max)
				y_max = i % 4 + 1;
			if (i % 4 + 1 < y_min)
				y_min = i % 4 + 1;
		}
		i++;
	}
	return (y_max - y_min + 1);
}

int		ft_points(char *piece, int points, int y, int j)
{
	int tab[2];

	tab[0] = -1;
	tab[1] = -1;
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
	if (tab[0] - tab[1] >= 3 || tab[1] == -1)
		return (0);
	return (tab[0] - tab[1]);
}

char	*ft_new_piece(char *piece, int points, int blocks, int i)
{
	char	*new;
	int		j;

	j = 0;
	while (piece[i] == '.')
		i++;
	new = (char*)malloc(sizeof(char) * (ft_strlen(piece) - i + 1));
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
	ft_strdel(&piece);
	return (new);
}

char	*ft_piece(char *piece)
{
	int		points;
	int		i;
	char	*tmp;

	i = 0;
	points = ft_points(piece, 0, 0, 0);
	piece = ft_new_piece(ft_strrev_fr(piece), points, 0, 0);
	tmp = ft_strrev_fr(piece);
	piece = tmp;
	ft_strdel(&tmp);
	return (piece);
}
