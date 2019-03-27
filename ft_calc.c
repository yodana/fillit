/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:58:18 by yodana            #+#    #+#             */
/*   Updated: 2019/03/27 11:08:07 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_point(char *piece)
{
	int i;

	i = 0;
	while (piece[i] != '#')
		i++;
	return (i);
}

void	ft_calc_x_y(int points, int *y, int *x, int y_max)
{
	if (points > 0)
		*y = *y + points - (5 - y_max);
	if (((*y % y_max) == 0 && *y != 0) || *y > y_max - 1)
	{
		if (*y > y_max - 1)
			*y = *y % y_max;
		else
			*y = 0;
		*x = *x + 1;
	}
}
