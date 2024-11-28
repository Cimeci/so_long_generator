/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:39:48 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/28 17:42:15 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill_recursive(char **map, t_point start)
{
	if (map[start.x][start.y] == '1')
		return ;
	map[start.x][start.y] = '1';
	flood_fill_recursive(map, (t_point){start.x + 1, start.y});
	flood_fill_recursive(map, (t_point){start.x - 1, start.y});
	flood_fill_recursive(map, (t_point){start.x, start.y + 1});
	flood_fill_recursive(map, (t_point){start.x, start.y - 1});
	return ;
}

static int	flood_fill(char **map, t_point start)
{
	int	i;
	int	j;

	flood_fill_recursive(map, start);

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E' || map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_count_char(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == c)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int	ft_check_count_char(char **map)
{
	t_count	count;

	count.c = ft_count_char(map, 'C');
	count.e = ft_count_char(map, 'E');
	count.p = ft_count_char(map, 'P');
	if (count.c == 0 || count.e != 1 || count.p != 1)
	{
		ft_printf("Error\nnumber of used char is false\n");
		ft_free_map(map);
		return (0);
	}
	return (1);
}

int	main_extension(char **argv)
{
	char	**map;
	int		flood;
	t_point	start;

	map = ft_map(argv);
	if (!map)
		return (0);
	if (ft_strlen(map[0]) == 3 && !(ft_check_len_3(argv)))
		return (0);
	else if (ft_strlen(map[0]) == 3 && ft_check_len_3(argv))
		return (1);
	if (!ft_check_count_char(map))
		return (0);
	start = ft_locate(map, 'P');
	flood = flood_fill(map, (t_point){start.x, start.y});
	if (flood == 0)
	{
		ft_printf("Error\nnumber of char find by flood_fill is false\n");
		ft_free_map(map);
		return (0);
	}
	ft_free_map(map);
	return (1);
}
