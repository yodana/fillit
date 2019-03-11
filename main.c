/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
/*   Updated: 2019/03/11 18:48:33 by arbocqui         ###   ########.fr       */
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

char	**ft_stock_map(int fd, char *line, char **map)
{
	int		i;

	i = 0;
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		if (map[i] == NULL)
			map[i] = ft_strdup("\n");
		i++;
	}
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
	piece->map = ft_piece(piece->map);
	return (piece);
}

int			main(int argc, char **argv)
{
	int fd;
	char *line;
	char **map;
	t_tetris *piece;
	t_final_map *final_map;

	line = NULL;
	if (!(map = (char**)malloc(sizeof(char*) * 1)))
		return (0);
	final_map = ft_new_map(4, 4);
	fd = open(argv[1], O_RDONLY);
	if (argc !=	 2)
	{
		ft_putendl("usage: ./fillit tetris_file");
		return (0);
	}
	piece = ft_new_tetris();
	map = ft_stock_map(fd, line, map);
	ft_check_line(map, 0, 0);
	piece = ft_add_piece(map, piece);
	printf("piece = %s\n",piece->map);
	//ft_resolv(final_map,piece, 0, 0);
	return (0);
}
