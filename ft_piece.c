/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:16:45 by yodana            #+#    #+#             */
/*   Updated: 2019/03/20 00:24:06 by arbocqui         ###   ########.fr       */
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
			while ((i + 1) % 4 != 0 && i != 0)
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
	int tmp;

	tmp = 0;
	y_max = 0;
	i = 0;
	if (ft_strstr(piece, "##...##" )!= NULL)
			return (4);
	while(piece[i])
	{
		if (piece[i] == '#')
			tmp++;
		if (((i + 1) % 4) == 0 && i != 0)
		{
			if (tmp > y_max)
				y_max = tmp;
			tmp = 0;
		}
			i++;
	}
	return (y_max);
}

int		ft_points(char *piece)
{
	int points;
	int y;
	int j;
	int	tab[2];

	y = 0;
	j = 0;
	points = 1;
	tab[1] = 1;
	while (piece[j])
	{
		if (piece[j] == '#')
		{
			tab[y] = points;
			points = 0;
			if (y < 1)
				y++;
			while ((j + 1) % 4 != 0)
				j++;
		}
		if ((j + 1) % 4 == 0)
			points = 0;
		j++;
		points++;
	}
	printf("piece points == %s\n", piece);
	printf("points == %d\n", tab[0]);
	return(tab[0] - tab[1]);
}

char	*ft_new_piece(char *piece, int points, int blocks)
{
	int i;
	char *new;
	int j;

	j = 0;
	new = (char*)malloc(sizeof(char) * 100);
	i = 0;
	printf("piece la %s\n", piece);
	while (piece[i] == '.')
		i++;
// while (blocks < 4)
	while (piece[i])
	{
		if (piece[i] == '#')
			blocks++;
		new[j] = piece[i];
		j++;
		i++;
	}
	(void)points;
/*	new[j] = piece[i];
	j++;
	points = -points;
	printf("points new piece %d \n", points);
	while (points > 0)
	{
		points--;
		new[j] = '.';
		j++;
	}*/
	new[j] = '\0';
	printf("new piece avec points %s\n", new);
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
	printf("piece = %s\n", new);
	return (new);
}
