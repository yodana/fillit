/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 06:14:26 by yodana            #+#    #+#             */
/*   Updated: 2019/03/05 17:16:54 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_error()
{
	ft_putstr("error");
	exit(0);
}

int			ft_end_block(int i)
{
	if ((i + 1) % 5 == 0)
		return (1);
	return (0);
}

int			ft_block(int i, int j, char **map)
{
	int		count;
	int		count_line;
	int		k;

	k = 0;
	count_line = 0;
	count = 0;
	while (map[k])
		k++;
	if (j < 3 && map[i][j + 1] == '#')
		count++;
	if (j > 0 && map[i][j - 1] == '#')
		count++;
	if (i < k && (i != (k - 1)) && map[i + 1][j] == '#')
		count++;
	if (i > 0 && map[i - 1][j] == '#')
		count++;
	return (count);
}

void	ft_check_errors(int i, int links, int blocks)
{
	if (ft_end_block(i) && (links != 6 && links != 8))
		ft_error();
	if (ft_end_block(i) && (blocks != 4))
		ft_error();
}

void		ft_check_line(char **map, int i, int j)
{
	int blocks;
	int	links;

	links = 0;
	blocks = 0;
	while (map[i] != NULL)
	{
		while (map[i][j])
		{
			if (!ft_end_block(i) && (map[i][j] != '.' && map[i][j] != '#'))
				ft_error();
			links = (map[i][j] == '#') ? links + ft_block(i, j, map) : links;
			blocks = (map[i][j] == '#') ? blocks + 1 : blocks;
			j++;
		}
		if (!(ft_end_block(i)) && j != 4)
			ft_error();
		ft_check_errors(i, links, blocks);
		blocks = (ft_end_block(i)) ? 0 : blocks;
		links = (ft_end_block(i)) ? 0 : links;
		i++;
		j = 0;
	}
	ft_check_errors(i, links, blocks);
	((i + 1) % 5 != 0 || i >= 130) ? ft_error() : 0;
}
