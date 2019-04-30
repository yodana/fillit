/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:26:16 by yodana            #+#    #+#             */
/*   Updated: 2019/04/30 17:42:12 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

void			ft_error();
void			ft_error_f(int fd);
void			ft_check_line(char **map, int i, int j);
char			*ft_piece(char *piece);
int				ft_calc_y(char *piece);
int				ft_calc_x(char *piece);

typedef struct	s_tetris
{
	char				*map;
	struct s_tetris		*next;
	int					y_max;
	int					x_max;
	char				lettre;
}				t_tetris;

typedef struct	s_final_map
{
	char				**sol;
	int					x;
	int					y;
	struct s_final_map	*next;
}				t_final_map;

int				ft_resolv(t_final_map *final_map, t_tetris *piece);
t_tetris		*ft_new_tetris();
t_final_map		*ft_new_map(int side);
int				ft_tetris_count(t_tetris *lst);
void			ft_free_lst(t_tetris **piece);
void			ft_free_map(char **map);
void			ft_tetrisadd(t_tetris **piece, t_tetris *n);
void			ft_final_map_fr(t_final_map *final_map);
void			ft_piece_fr(t_tetris *piece);
void			ft_print(int y, char **sol);
int				ft_point(char *piece);
void			ft_calc_x_y(int points, int *y, int *x, int y_max);

#endif
