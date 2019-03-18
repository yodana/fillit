/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
/*   Updated: 2019/03/18 18:02:23 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_lstajout(t_tetris **piece, t_tetris *new)
{
	if (piece && new)
	{
		new->next = *piece;
		*piece = new;
	}
}

char	**ft_stock_map(char *argv, char *line, char **map)
{
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
		i++;
	close(fd);
	if (!(map = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		if (map[i] == NULL)
			map[i] = ft_strdup("\n");
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

t_tetris	*ft_add_piece(char **map, t_tetris *piece)
{
	int	i;
	int	j;
	t_tetris *new;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
			if ((i + 1) % 5 == 0)
			{
				piece->y_max = ft_calc_y(piece->map);
				piece->x_max = ft_calc_x(piece->map);
				piece->map = ft_piece(piece->map);
				printf("piece = %s\n",piece->map);
				ft_putchar('\n');
				new = ft_new_tetris();
				ft_lstajout(&piece,new);
				piece = new;
				i++;
				j = 0;
			}
			piece->map = ft_strjoin(piece->map, map[i]);
			j++;
			i++;
	}
	piece->y_max = ft_calc_y(piece->map);
	piece->x_max = ft_calc_x(piece->map);
	printf("x max de la piece = %d\n",piece->x_max);
	piece->map = ft_piece(piece->map);
	return (piece);
}

int			main(int argc, char **argv)
{
	char *line;
	char **map;
	t_tetris *piece;
	t_final_map *final_map;

	line = NULL;
	if (!(map = (char**)malloc(sizeof(char*))))
		return (0);
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetris_file");
		return (0);
	}
	piece = ft_new_tetris();
	map = ft_stock_map(argv[1], line, map);
	ft_check_line(map, 0, 0);
	piece = ft_add_piece(map, piece);
	t_tetris *begin = piece;
	printf("lst nbr = %d\n,",ft_sqrt(8));
	int nbr_t = ft_tetris_count(piece);
	int i = 1;
	while (nbr_t * 4 >= i * i)
		i++;
	printf("i = %d\n",i); 
	final_map = ft_new_map(4);
	printf("piece = %s\n",piece->map);
	ft_putchar('\n');
	ft_resolv(final_map,piece, 0,0,begin);
	return (0);
}
