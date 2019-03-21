/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yodana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:10:26 by yodana            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/03/21 03:13:34 by yodana           ###   ########.fr       */
=======
/*   Updated: 2019/03/20 00:22:49 by arbocqui         ###   ########.fr       */
>>>>>>> b71d12564ea791d59541849a4d4e8379502fa885
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

/*
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
*/

void	ft_lstajout(t_tetris **piece, t_tetris *new, char *temp)
{
	t_tetris	*tmp;

	new = ft_new_tetris(temp);
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
		i++;
	close(fd);
	if (!(map = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
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
	tmp = ft_strnew(0);
<<<<<<< HEAD
	int count = 0;
	while (map[i])
=======
	new = NULL;
	while (map[i] != NULL)
>>>>>>> b71d12564ea791d59541849a4d4e8379502fa885
	{
		tmp = ft_strjoin(tmp, map[i]);
		if ((i + 1) % 5 == 0)
		{
<<<<<<< HEAD
			if (i == 4)
			{
				piece = ft_new_tetris(tmp, count);
			}
				else
			{
				new = ft_new_tetris(tmp,count);
				ft_lstajout(&piece, new);
			}
=======
			(i == 4) ?
				piece = ft_new_tetris(tmp) : ft_lstajout(&piece, new, tmp);
>>>>>>> b71d12564ea791d59541849a4d4e8379502fa885
			tmp = ft_strnew(0);
			count++;
		}
		i++;
	}
<<<<<<< HEAD
	if (i == 4)
		piece = ft_new_tetris(tmp,count);
	else
	{
		new = ft_new_tetris(tmp,count);
		ft_lstajout(&piece, new);
	}
		return (piece);
=======
	(i == 4) ? piece = ft_new_tetris(tmp) : ft_lstajout(&piece, new, tmp);
	return (piece);
>>>>>>> b71d12564ea791d59541849a4d4e8379502fa885
}

int			main(int argc, char **argv)
{
	char *line;
	char **map;
	t_tetris *piece;
//	t_final_map *final_map;

	line = NULL;
	if (!(map = (char**)malloc(sizeof(char*))))
		return (0);
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit tetris_file");
		return (0);
	}
	map = ft_stock_map(argv[1], line, map);
	ft_check_line(map, 0, 0);
	piece = ft_add_piece(map);
//	t_tetris *begin = piece;
/*	printf("lst nbr = %d\n,",ft_sqrt(8));
int nbr_t = ft_tetris_count(piece);
int i = 1;	
while (nbr_t * 4 > i * i)
	i++;
printf("i = %d\n",i); 
	final_map = ft_new_map(i);
	printlist(begin);
	ft_putchar('\n');
	int z;
<<<<<<< HEAD
	z = 0;
	int nbr_p = 0;
	while(ft_resolv(final_map,begin,nbr_p,begin) != 1)
	{
=======
	z = 0;*/
//	ft_resolv(final_map,begin, 0,0,begin);
	/*{
>>>>>>> b71d12564ea791d59541849a4d4e8379502fa885
		i++;
		free(final_map);
		t_final_map *new = ft_new_map(i);
		final_map = new;
	}
	return (0);
}
