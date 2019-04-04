/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 03:13:22 by yodana            #+#    #+#             */
/*   Updated: 2019/04/04 17:51:23 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_gnl(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
			return (-1);
		i++;
	}
	return (0);
}

void	ft_final_map_fr(t_final_map *final_map)
{
	ft_strrdel(final_map->sol);
	free(final_map);
}

void	ft_piece_fr(t_tetris *piece)
{
	t_tetris *tmp;

	while (piece)
	{
		ft_strdel(&(piece->map));
		tmp = piece->next;
		free(piece);
		piece = tmp;
	}
}
