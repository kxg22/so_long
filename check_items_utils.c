/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_items_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:13:58 by gansard           #+#    #+#             */
/*   Updated: 2023/02/08 21:18:20 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_dup_map(char **map)
{
	int		i;
	char	**d_map;

	i = 0;
	while (map[i])
		i++;
	d_map = malloc(sizeof(char *) * i + 1);
	if (!d_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		d_map[i] = ft_strdup(map[i]);
		i++;
	}
	d_map[i] = NULL;
	return (d_map);
}

int	ft_put_p(char **d_map, int x, int y, int *count_c)
{
	if (d_map[x][y] == 'C')
	{
		d_map[x][y] = 'P';
		(*count_c)--;
		return (1);
	}
	if (d_map[x][y] == '0')
	{
		d_map[x][y] = 'P';
		return (1);
	}
	if (d_map[x][y] == 'E')
	{
		d_map[x][y] = '1';
		return (1);
	}
	return (0);
}

int	ft_check_items(char **map, int *count_c)
{
	char	**d_map;
	int		x;
	int		y;
	int		nb_modif;

	x = 1;
	y = 1;
	nb_modif = 1;
	d_map = ft_dup_map(map);
	if (!d_map)
		return (0);
	while (nb_modif)
	{
		nb_modif = 0;
		while (d_map[x])
		{
			while (d_map[x][y])
			{
				if (d_map[x][y] == 'P')
				{
					nb_modif += ft_put_p(d_map, x, (y + 1), count_c);
					nb_modif += ft_put_p(d_map, x, (y - 1), count_c);
					nb_modif += ft_put_p(d_map, (x + 1), y, count_c);
					nb_modif += ft_put_p(d_map, (x - 1), y, count_c);
				}
				y++;
			}
			y = 0;
			x++;
		}
		x = 0;
	}
	ft_free_map(d_map);
	if (*count_c)
		return (0);
	return (1);
}
