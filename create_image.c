#include "so_long.h"

static void	out_subject(t_var_image var_image, t_sprites sprites, \
t_var_map *var_map)
{
	if (var_map->count_fire <= var_map->count_water && \
	 var_map->count_fire <= var_map->count_land)
	{
		mlx_put_image_to_window(var_image.mlx, var_image.win, \
		 sprites.fire, var_map->x, var_map->y);
		var_map->count_fire++;
	}
	else if (var_map->count_water <= var_map->count_fire && \
	 var_map->count_water <= var_map->count_land)
	{
		mlx_put_image_to_window(var_image.mlx, var_image.win, \
		 sprites.water, var_map->x, var_map->y);
		var_map->count_water++;
	}
	else
	{
		mlx_put_image_to_window(var_image.mlx, var_image.win, \
		 sprites.land, var_map->x, var_map->y);
		var_map->count_land++;
	}
}

static void	init_sprite(t_sprites *sprite, t_var_image var_image)
{
	int		w;
	int		h;

	sprite->avatar = mlx_xpm_file_to_image(var_image.mlx, "avatar.xpm", \
	 &w, &h);
	sprite->water = mlx_xpm_file_to_image(var_image.mlx, "water.xpm", \
	 &w, &h);
	sprite->empty = mlx_xpm_file_to_image(var_image.mlx, "empty.xpm", \
	 &w, &h);
	sprite->wall = mlx_xpm_file_to_image(var_image.mlx, "wall.xpm", \
	 &w, &h);
	sprite->fire = mlx_xpm_file_to_image(var_image.mlx, "fire.xpm", \
	 &w, &h);
	sprite->land = mlx_xpm_file_to_image(var_image.mlx, "land.xpm", \
	 &w, &h);
	sprite->out = mlx_xpm_file_to_image(var_image.mlx, "out.xpm", &w, &h);
}

static void	init_var_map(t_var_map *var_map)
{
	var_map->i = 0;
	var_map->y = 0;
	var_map->count_fire = 0;
	var_map->count_land = 0;
	var_map->count_water = 0;
}

static void	out_sprites(t_var_image *var_image, t_var_map *var_map, \
t_sprites *sprites)
{
	if (var_image->map[var_map->i][var_map->j] == '1')
		mlx_put_image_to_window(var_image->mlx, var_image->win, \
			sprites->wall, var_map->x, var_map->y);
	else if (var_image->map[var_map->i][var_map->j] == '0')
		mlx_put_image_to_window(var_image->mlx, var_image->win, \
			sprites->empty, var_map->x, var_map->y);
	else if (var_image->map[var_map->i][var_map->j] == 'P')
		mlx_put_image_to_window(var_image->mlx, var_image->win, \
			sprites->avatar, var_map->x, var_map->y);
	else if (var_image->map[var_map->i][var_map->j] == 'E')
		mlx_put_image_to_window(var_image->mlx, var_image->win, \
			sprites->out, var_map->x, var_map->y);
	else
		out_subject(*var_image, *sprites, var_map);
}

void	create_image(t_var_image var_image)
{
	t_var_map	var_map;
	t_sprites	sprites;

	var_image.width *= 30;
	var_image.height *= 30;
	init_var_map(&var_map);
	init_sprite(&sprites, var_image);
	while (var_map.y < var_image.height)
	{
		var_map.j = 0;
		var_map.x = 0;
		while (var_map.x < var_image.width)
		{
			out_sprites(&var_image, &var_map, &sprites);
			var_map.j++;
			var_map.x += 30;
		}
		var_map.i++;
		var_map.y += 30;
	}
	out_count_move(&var_image);
}
