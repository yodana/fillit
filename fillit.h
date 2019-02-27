/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:26:16 by yodana            #+#    #+#             */
/*   Updated: 2019/02/26 22:09:33 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

void	ft_error();
void	ft_check_line(char **map, int i, int j);
typedef struct s_tetris
{
	char map[4][4];
	struct s_tetris *next;
}				t_tetris;


#endif
