/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpiece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:21:24 by yodana            #+#    #+#             */
/*   Updated: 2019/02/18 18:34:01 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris	*ft_new_tetris()
{
	t_tetris *new;

	new = malloc(sizeof(t_tetris));
	new->next = NULL;
	new->map = (char**)malloc(sizeof(char) * 1);
	return (new);
}
