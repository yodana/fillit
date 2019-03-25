/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 00:38:04 by yodana            #+#    #+#             */
/*   Updated: 2019/03/25 06:19:28 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 00:38:02 by yodana            #+#    #+#             */
/*   Updated: 2019/03/21 00:38:02 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 15:26:16 by yodana            #+#    #+#             */
/*   Updated: 2019/03/21 00:18:12 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

void	ft_error();
void	ft_check_line(char **map, int i, int j);
char	*ft_piece(char *piece);
int		ft_calc_y(char *piece);
int		ft_calc_x(char *piece);
typedef struct s_tetris
{
	char *map;
	struct s_tetris *next;
	int y_max;
	int x_max;
	char lettre;
}				t_tetris;

typedef struct s_final_map
{
	char **sol;
	int x;
	int y;
	struct s_final_map *next;
}				t_final_map;
int		ft_resolv(t_final_map *final_map, t_tetris *piece);
t_tetris	*ft_new_tetris();
t_final_map *ft_new_map(int side);
int			ft_tetris_count(t_tetris *lst);
void	ft_free_lst(t_tetris **piece);
#endif
