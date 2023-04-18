/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelahce <abelahce@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 01:30:37 by abelahce          #+#    #+#             */
/*   Updated: 2023/04/03 03:40:59 by abelahce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
}

void	free_table(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i++]);
	}
	if (tab)
		free(tab);
}

void	free_data(t_cub *data)
{
	ft_free(data->info->c);
	ft_free(data->info->f);
	ft_free(data->info->no);
	ft_free(data->info->we);
	ft_free(data->info->so);
	ft_free(data->info->ea);
	free(data->info);
	free(data->ply);
	ft_free(data->map_name);
	ft_free(data->map);
	free_table(data->map_final);
	free(data->info->sky_color);
	free(data->info->floor_color);
	free(data);
}

void	ft_error(char *str, t_cub *data)
{
	ft_putstr_fd(str, 2);
	if (data)
		free_data(data);
	exit(0);
}

void	check_leaks(void)
{
	system("leaks cub3d");
}
