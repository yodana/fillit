/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
/*   Updated: 2019/02/27 18:29:29 by arbocqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>
char	**ft_realloc(char **map, int old_size)
{
	char **tmp;

	tmp = malloc(sizeof(char) * old_size);
	tmp = map;
	map = malloc(old_size + 1);
	return (map);
}	

void	ft_lstajout(t_tetris **piece, t_tetris *new)
{
	if (piece && new)
	{
		new->next = *piece;
		*piece = new;
	}
}
int main(int argc, char **argv)
{
	int fd;
	char *line;
	char **map = malloc(10000);
	int i = 0;
	int size = 1;
	fd = open(argv[1], O_RDONLY);
	t_tetris *piece;
	t_final_map *final_map;
	final_map = ft_new_map();
	if (argc !=	 2)
	{
		ft_putendl("usage: ./fillit tetris_file");
		return (0);
	}
	piece = ft_new_tetris();
	while (get_next_line(fd, &line))
	{
//		map = ft_realloc(map, size);
		map[i] = ft_strnew(0);
		map[i] = ft_strdup(line);
		if (map[i] == NULL)
			map[i] = ft_strdup("\n");
		i++;
		size++;
	}
	map[i] = NULL;
	i = 0;
	int j = 0;
	ft_check_line(map, 0, 0);
	while(map[i] != NULL)
	{
			if ((i + 1) % 5 == 0)
			{
				ft_putchar('\n');
				t_tetris *new = ft_new_tetris();
				ft_lstajout(&piece,new);
				piece = new;
				i++;
				j = 0;
			}
			((char**)piece->map)[j] = ft_strdup(map[i]);
			printf("i = %d map = %s | piece = %s\n",i,map[i],(((char**)piece->map)[j]));
			j++;
			i++;
	}
	i = 0;
	/*while (piece)
	{
		ft_putstr("lol");
		while (((char**)piece->map)[i])
		{
			printf("i = %d %s\n",i,((char**)piece->map)[i]);
			i++;
		}
		i = 0;
		piece = piece->next;
		ft_putchar('\n');
	}*/
	ft_resolv(final_map, piece, 0, 0);
	return (0);
}
