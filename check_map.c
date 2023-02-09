/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:30:19 by gansard           #+#    #+#             */
/*   Updated: 2023/02/08 18:51:00 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_rectangle(char **map, int *nb_lines)
{
	int	i;
	int	first_line_len;

	first_line_len = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != first_line_len)
			return (0);
		i++;
	}
	*nb_lines = i;
	return (1);
}

int	ft_check_walls(char **map, int nb_lines)
{
	int	i;
	int	nb_columns;

	i = 0;
	while (map[0][i] && map[nb_lines - 1][i])
	{
		if (map[0][i] != '1' || map[nb_lines - 1][i] != '1')
			return (0);
		i++;
	}
	nb_columns = i;
	i = 0;
	while (i < nb_lines)
	{
		if (map[i][0] != '1' || map[i][nb_columns - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_map(char **map, int *count_c)
{
	int	nb_lines;

	if (!ft_check_rectangle(map, &nb_lines))
	{
		ft_printf("Error \nLa carte n'est pas rectangulaire.\n");
		return (0);
	}
	if (!ft_check_walls(map, nb_lines))
	{
		ft_printf("Error \nLa carte n'est pas entourée de murs.\n");
		return (0);
	}
	if (!ft_check_items(map, count_c))
	{
		ft_printf("Error \nTous les colletables ne sont pas accessibles.");
		return (0);
	}
	return (1);
}
