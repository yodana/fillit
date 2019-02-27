/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:26:16 by yodana            #+#    #+#             */
/*   Updated: 2019/02/27 18:32:28 by arbocqui         ###   ########.fr       */
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
	char **map;
	struct s_tetris *next;
}				t_tetris;

typedef struct s_final_map
{
	char **sol;
	int x;
	int y;
	struct s_final_map *next;
}				t_final_map;
void		ft_resolv(t_final_map *final_map, t_tetris *piece, int x, int y);
t_tetris	*ft_new_tetris();
t_final_map *ft_new_map();

#endif
