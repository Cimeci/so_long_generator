/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inowak-- <inowak--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:25 by inowak--          #+#    #+#             */
/*   Updated: 2024/11/19 14:49:02 by inowak--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup(t_data *data)
{
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->empty)
		mlx_destroy_image(data->mlx, data->empty);
	if (data->object)
		mlx_destroy_image(data->mlx, data->object);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	ft_free_map(data->map);
}

void	free_images(t_data *params)
{
	if (params->wall)
		mlx_destroy_image(params->mlx, params->wall);
	if (params->empty)
		mlx_destroy_image(params->mlx, params->empty);
	if (params->object)
		mlx_destroy_image(params->mlx, params->object);
	if (params->player)
		mlx_destroy_image(params->mlx, params->player);
	if (params->exit)
		mlx_destroy_image(params->mlx, params->exit);
}

char	**ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

int	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error\nfile map false");
		return (0);
	}
	return (1);
}
