/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:18:20 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/19 16:02:21 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_count_line(char **argv)
{
	int		fd;
	size_t	count;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	count = 0;
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	*ft_map_extension(int j, char *line, char **map)
{
	int	i;

	i = 0;
	map[j] = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!map[j])
	{
		while (j-- > 0)
			free(map[j]);
		free(map);
		return (NULL);
	}
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		map[j][i] = line[i];
		i++;
	}
	map[j][i] = '\0';
	free(line);
	return (map[j]);
}

char	**ft_map(char **argv)
{
	char	**map;
	int		j;
	int		line_count;
	int		fd;
	char	*line;

	j = 0;
	line_count = ft_count_line(argv);
	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	fd = open(argv[1], O_RDONLY);
	if (ft_check_fd(fd) == 0)
		return (0);
	while (j < line_count || get_next_line(fd))
	{
		line = get_next_line(fd);
		map[j] = ft_map_extension(j, line, map);
		if (!map[j])
			return (NULL);
		j++;
	}
	map[j] = NULL;
	close(fd);
	return (ft_check_map(map, argv));
}
