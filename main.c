/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
/*   Updated: 2019/03/25 06:19:52 by yodana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>


void	printlist(t_tetris *piece)
{
	while (piece)
	{
		ft_putstr(piece->map);
		ft_putstr("\t->\t");
		piece = piece->next;
	}
	ft_putstr("NULL");
}


void	ft_lstajout(t_tetris **piece, t_tetris *new)
{
	t_tetris	*tmp;

	if (new)
	{
		tmp = *piece;
		if (tmp == NULL)
			tmp = new;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

char	**ft_stock_map(char *argv, char *line, char **map)
{
	int		i;
	int		fd;

	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	close(fd);
	if (!(map = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}

t_tetris	*ft_add_piece(char **map)
{
	int			i;
	char		*tmp;
	t_tetris	*new;
	t_tetris	*piece;

	i = 0;
	int count = 0;
	tmp = ft_strnew(0);
	while (map[i])
	{
		tmp = ft_strjoin_fr(tmp, map[i],  1);
		if ((i + 1) % 5 == 0)
		{
			if (i == 4)
			{
				piece = ft_new_tetris(tmp, count);
			}
				else
			{
				new = ft_new_tetris(tmp,count);
				ft_lstajout(&piece, new);
			}
			tmp = ft_strnew(0);
			count++;
		}
		i++;
	}
	if (i == 4)
		piece = ft_new_tetris(tmp,count);
	else
	{
		new = ft_new_tetris(tmp,count);
		ft_lstajout(&piece, new);
	}
		return (piece);
}

void		ft_piece_fr(t_tetris *piece)
{

	while (piece)
	{
		ft_strdel(&(piece->map));
		free(piece);
		piece = piece->next;
	}
}

void		ft_free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_strdel(&map[i]);
		i++;
	}
}

void		ft_final_map_fr(t_final_map *final_map)
{
	ft_free_map(final_map->sol);
	free(final_map);
}

int			main(int argc, char **argv)
{
	char **map;
	char *line;
	t_tetris *piece;
	t_final_map *final_map;
	line = NULL;
	map = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetris_file");
		return (0);
	}
	map = ft_stock_map(argv[1], line, map);
	ft_check_line(map, 0, 0);
	piece = ft_add_piece(map);
	ft_free_map(map);
	printf("lst nbr = %d\n,",ft_sqrt(8));
	int nbr_t = ft_tetris_count(piece);
int i = 1;	
	while (nbr_t * 4 > i * i)
	i++;
printf("i = %d\n",i); 
final_map = ft_new_map(i);
i = 0;


printlist(piece);
	ft_putchar('\n');
	int z;
	z = 0;
	while(ft_resolv(final_map,piece) != 1)
	{
		i++;
		ft_final_map_fr(final_map);
		t_final_map *new = ft_new_map(i);
		final_map = new;
	}
	ft_final_map_fr(final_map);
	ft_piece_fr(piece);
	return (0);
}
