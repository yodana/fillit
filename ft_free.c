/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 03:13:22 by yodana            #+#    #+#             */
/*   Updated: 2019/03/27 03:24:21 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_final_map_fr(t_final_map *final_map)
{
	ft_strrdel(final_map->sol);
	free(final_map);
}

void	ft_piece_fr(t_tetris *piece)
{
	while (piece)
	{
		ft_strdel(&(piece->map));
		free(piece);
		piece = piece->next;
	}
}
