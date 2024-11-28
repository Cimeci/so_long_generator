/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_len_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:03:06 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/28 13:27:06 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_len_3(char **argv)
{
	size_t i;
	size_t j;
    char **map;

    map = ft_map(argv);
    j = 1;
    i = 0;
	while (j < ft_count_line(argv) - 1)
	{
		i = 0;
		while (map[j][i])
		{
            // ft_printf("%c ", map[j][i]);
			if (map[j][1] == '1')
            {
                ft_printf("Error\nnumber of char find by check_3 is false\n");
                ft_free_map(map);
				return (0);
            }
            i++;
		}
		j++;
	}
    ft_free_map(map);
	return (1);
}
