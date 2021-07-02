#include "so_long.h"

static void	get_pos_player(t_var_image *var_image, t_position *pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < var_image->height)
	{
		j = 0;
		while (j < var_image->width)
		{
			if (var_image->map[i][j] == 'P')
			{
				pos->player_x = j;
				pos->player_y = i;
				break ;
			}
			j++;
		}
		if (j < (var_image->width - 1))
			break ;
		i++;
	}
}

static void	get_pos_move(int key, t_position *pos)
{
	if (key == 13)
	{
		pos->move_pos_x = pos->player_x;
		pos->move_pos_y = pos->player_y - 1;
	}
	else if (key == 1)
	{
		pos->move_pos_x = pos->player_x;
		pos->move_pos_y = pos->player_y + 1;
	}
	else if (key == 0)
	{
		pos->move_pos_x = pos->player_x - 1;
		pos->move_pos_y = pos->player_y;
	}
	else
	{
		pos->move_pos_x = pos->player_x + 1;
		pos->move_pos_y = pos->player_y;
	}
}

static void	move_c_e(t_var_image *var_image, t_position *pos)
{
	if (var_image->map[pos->move_pos_y][pos->move_pos_x] == 'C')
	{
		var_image->count_subj++;
		var_image->count_move++;
		if (var_image->pos_exit_x == pos->player_x && \
		 var_image->pos_exit_y == pos->player_y)
			var_image->map[pos->player_y][pos->player_x] = 'E';
		else
			var_image->map[pos->player_y][pos->player_x] = '0';
		var_image->map[pos->move_pos_y][pos->move_pos_x] = 'P';
	}
	else if (var_image->map[pos->move_pos_y][pos->move_pos_x] == 'E')
	{
		var_image->count_move++;
		if (var_image->count_subj == var_image->total_subj)
			exit(0);
		var_image->map[pos->player_y][pos->player_x] = '0';
		var_image->map[pos->move_pos_y][pos->move_pos_x] = 'P';
	}
}

static void	work_move(int key, t_var_image *var_image)
{
	t_position	pos;

	get_pos_player(var_image, &pos);
	get_pos_move(key, &pos);
	move_c_e(var_image, &pos);
	if (var_image->map[pos.move_pos_y][pos.move_pos_x] == '0')
	{
		var_image->count_move++;
		if (var_image->pos_exit_x == pos.player_x && \
		 var_image->pos_exit_y == pos.player_y)
			var_image->map[pos.player_y][pos.player_x] = 'E';
		else
			var_image->map[pos.player_y][pos.player_x] = '0';
		var_image->map[pos.move_pos_y][pos.move_pos_x] = 'P';
	}
	if (var_image->map[pos.move_pos_y][pos.move_pos_x] != '1')
	{
		ft_putnbr(var_image->count_move);
		write(1, "\n", 1);
	}
	create_image(*var_image);
}

int	work_clicks(int key, t_var_image *var_image)
{
	if (key == 0 || key == 1 || key == 2 || key == 13)
		work_move(key, var_image);
	else if (key == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
