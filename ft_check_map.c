/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:18:20 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/28 14:01:01 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
	{
		ft_printf("Error\nfirst or last caracter is false\n");
		return (0);
	}
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C' && line[i] != 'E'
			&& line[i] != 'P')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_start_last(char **map, char **argv)
{
	int	i;
	int	last;

	last = ft_count_line(argv);
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[last - 1][i])
	{
		if (map[last - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_len(char **map, char **argv)
{
	size_t	origine_len;
	int		j;

	j = 1;
	origine_len = ft_strlen(map[0]);
	while (map[j])
	{
		if (ft_strlen(map[j]) != origine_len)
			return (0);
		j++;
	}
	(void)argv;
	// if (origine_len + 1 == ft_count_line(argv))
	// 	return (0);
	return (1);
}

static int	ft_check_map_extension_1(char **map, char **argv)
{
	if (ft_check_len(map, argv) == 0)
	{
		ft_printf("Error\nlen of the line is false or not a rectangle\n");
		return (0);
	}
	if (ft_strlen(map[0]) + 1 > 60 || ft_count_line(argv) > 30)
	{
		ft_printf("Error\nlen of the map is too big\n");
		return (0);
	}
	if (ft_check_start_last(map, argv) == 0)
	{
		ft_printf("Error\nfirst or last line are false\n");
		return (0);
	}
	return (1);
}

char	**ft_check_map(char **map, char **argv)
{
	int	j;
	int	total_lines;

	total_lines = ft_count_line(argv);
	j = 1;
	if (ft_check_map_extension_1(map, argv) == 0)
		return (ft_free_map(map));
	while (map[j] && j < total_lines)
	{
		if (!ft_check_line(map[j]))
		{
			ft_printf("Error\ncaractere is false\n");
			return (ft_free_map(map));
		}
		j++;
	}
	return (map);
}
