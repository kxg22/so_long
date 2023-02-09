/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansard <gansard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:41:49 by gansard           #+#    #+#             */
/*   Updated: 2023/02/08 21:17:33 by gansard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// n'oubli pas de free si y a une erreur dans ft_check_format
char	**ft_so_long(char *src_map)
{
	char	**map;
	char	*map_str;
	int		count_c;
	int		i;

	i = 0;
	count_c = 0;
	map_str = ft_get_map(src_map);
	if (!map_str || !ft_check_format(map_str, &count_c))
		return (free(map_str), NULL);
	map = ft_split(map_str, '\n');
	free(map_str);
	if (!map)
		return (NULL);
	if (!ft_check_map(map, &count_c))
	{
		ft_free_map(map);
		return (NULL);
	}
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (map);
}

int	main(int ac, char **av, char **env)
{
	char	*src_map;
	char	**map;

	if (ac != 2)
		return (ft_printf("Error \nNombre d'arguments incorrect.\n"));
	src_map = av[1];
	if (!ft_check_name(src_map))
		return (0);
	map = ft_so_long(src_map);
	if (!map)
		return (0);
	ft_free_map(map);
	//ft_create_mlxMap(map);
	return (0);
}
