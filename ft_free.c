/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 03:13:22 by yodana            #+#    #+#             */
/*   Updated: 2019/04/30 17:44:00 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error_f(int fd)
{
	close(fd);
	ft_putendl("error");
	exit(0);
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
