/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
/*   Updated: 2019/02/21 16:32:52 by yodana           ###   ########.fr       */
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
	ft_check_line(map);
	while(map[i] != NULL)
	{
			if ((i + 1) % 5 == 0)
			{
				piece->next = ft_new_tetris();
				piece = piece->next;
				i++;
				j = 0;
			}
			((char**)piece->map)[j] = ft_strdup(map[i]);
			printf("i = %d map = %s | piece = %s\n",i,map[i],(((char**)piece->map)[j]));
			j++;
			i++;
	}
	ft_resolv(final_map, &piece, 0, 0);
	
	return (0);
}
