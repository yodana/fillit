/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 06:14:26 by yodana            #+#    #+#             */
/*   Updated: 2019/02/16 18:27:40 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_error()
{
	ft_putstr("error");
	exit(0);
}

void	ft_check_block(int i, int j, char **map)
{
	
}

int			ft_end_block(int i)
{
	if ((i + 1) % 5 == 0)
		return (1);
	return (0);
}
void		ft_check_line(char **map)
{
	int i;
	int j;
	int blocks;
	
	blocks = 0;
	j = 0;
	i = 0;
	while (map[i] != NULL)
	{
		while (map[i][j])
		{
			if ((((i + 1)  % 5 != 0)  && (map[i][j] != '.' && map[i][j] != '#')))
				ft_error();
			if (map[i][j] == '#')
			{
				blocks++;
			}
			j++;
		}
		if (!(ft_end_block(i)) && j != 4)
			ft_error();
		j = 0;
		i++;
		if (ft_end_block(i) && (blocks != 4))
		{
			ft_error();
		}
		else if (ft_end_block(i))
			blocks = 0;
	}
	printf("%d",i);
	if (i % 4 != 0 && i % 9 != 0)
	{
		ft_error();
	}
}
