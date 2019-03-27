/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:21:24 by yodana            #+#    #+#             */
/*   Updated: 2019/03/27 23:43:32 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#include <stdio.h>

void		ft_tetrisadd(t_tetris **piece, t_tetris *n)
{
	t_tetris	*tmp;

	if (n)
	{
		tmp = *piece;
		if (tmp == NULL)
			tmp = n;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = n;
		}
	}
}

int			ft_tetris_count(t_tetris *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

char		**ft_clean_map(int side, char **map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (side + 1))))
		return (NULL);
	while (x < side)
	{
		map[x] = ft_strnew(side);
		while (y < side)
		{
			map[x][y] = '.';
			y++;
		}
		map[x][y] = '\0';
		y = 0;
		x++;
	}
	map[x] = NULL;
	return (map);
}

t_final_map	*ft_new_map(int side)
{
	t_final_map *new;

	if (!(new = (t_final_map*)malloc(sizeof(t_final_map))))
		return (NULL);
	new->next = NULL;
	new->x = side;
	new->y = side;
	new->sol = ft_clean_map(side, new->sol);
	return (new);
}

t_tetris	*ft_new_tetris(char *map, int count)
{
	t_tetris	*new;
	char		*tmp;

	if (!(new = (t_tetris*)malloc(sizeof(t_tetris))))
		return (NULL);
	new->x_max = ft_calc_x(map);
	tmp = ft_piece(map);
	new->map = ft_strdup(tmp);
	new->y_max = ft_calc_y(new->map);
	new->lettre = 65 + count;
	new->next = NULL;
	free(tmp);
	return (new);
}
