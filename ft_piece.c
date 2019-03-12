/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_piece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:16:45 by yodana            #+#    #+#             */
/*   Updated: 2019/03/11 20:27:02 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
int		ft_points(char *piece)
{
	int points;
	int tab[2];
	int y;
	int j;

	y = 0;
	j = 0;
	points = 1;
	while (piece[j])
	{
		if (piece[j] == '#')
		{
			tab[y] = points;
			printf("tab = %d || y == %d\n",tab[y], y);
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
	printf(" points = %d\n",tab[0] - tab[1]);
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
	printf("points dans main = %d\n",points);
	new = ft_new_piece(ft_strrev(piece), points, 0);
	printf("%s\n",new);
	return (new);
}
