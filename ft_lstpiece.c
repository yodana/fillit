/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:21:24 by yodana            #+#    #+#             */
/*   Updated: 2019/02/19 18:15:26 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


t_final_map	*ft_new_map()
{
	t_final_map *new;

	new = malloc(sizeof(t_final_map));
	new->next = NULL;
	new->x_max = 4;
	new->y_max = 4;
	new->sol = (char**)malloc(sizeof(char) * 1);
	return (new);
}

t_tetris	*ft_new_tetris()
{
	t_tetris *new;

	new = malloc(sizeof(t_tetris));
	new->next = NULL;
	new->map = (char**)malloc(sizeof(char) * 1);
	return (new);
}
