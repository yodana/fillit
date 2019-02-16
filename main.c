/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
/*   Updated: 2019/02/16 16:11:34 by yodana           ###   ########.fr       */
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
	while(map[i])
	{
		printf("%s",map[i]);
		i++;
	}
	ft_check_line(map);
	/*
 *	while (map[i] != NULL)
	{
		ft_putnbr(ft_strlen(map[i]));
		ft_putchar('\n');
		ft_putendl(map[i]);
		if (ft_strlen(map[i]) != 4)
		{
			ft_error();
		}
		i++;
	}*/
	//while (map[i] != '\0')
	//{
	//	ft_putendl(map[i]);
	//	i++;
	//}
	if (argc != 2)
	{
		ft_putendl("usage : fillit tetris_file");
		return (0);
	}
	return (0);
}
