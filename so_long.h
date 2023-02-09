#ifndef SO_LONG_H

# define SO_LONG_H
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "libft/ft_printf.h"
# include <fcntl.h>
# include "./minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*player;
	void	*wall;
	void	*space;

}	t_data;
char*	ft_get_map(char *src_map);
void	ft_free_map(char **map);
int     ft_check_map(char **map, int *count_c);
int     ft_check_format(char *map_str, int *count_c);
int     ft_check_name(char *src_map);
char 	**ft_dup_map(char **map);
void 	ft_moveup(char **map, int *x, int *y, int *c_tofound);
void 	ft_moveright(char **map, int *x, int *y, int *c_tofound);
void 	ft_moveleft(char **map, int *x, int *y, int *c_tofound);
void 	ft_movedown(char **map, int *x, int *y, int *c_tofound);
int 	ft_check_items(char **map, int  *count_c);
void	ft_create_mlxMap(char	**map);

#endif