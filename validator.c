#include "so_long.h"

static void	count_symbol(char c, int *exit, int *start, int *thing)
{
	if (c == 'E')
		(*exit)++;
	else if (c == 'P')
		(*start)++;
	else if (c == 'C')
		(*thing)++;
}

static void	init_var_check(t_var_check *var)
{
	var->i = 0;
	var->exit = 0;
	var->start = 0;
	var->thing = 0;
}

static void	save_e_c(t_var_image *v_i, t_var_check *v)
{
	if (v_i->map[v->i][v->j] == 'E')
	{
		v_i->pos_exit_x = v->j;
		v_i->pos_exit_y = v->i;
	}
	if (v_i->map[v->i][v->j] == 'C')
		v_i->total_subj++;
}

static void	check_symbols(t_var_image *v_i)
{
	t_var_check	v;

	init_var_check(&v);
	while (v_i->map[v.i] != NULL)
	{
		v.j = 0;
		while (v_i->map[v.i][v.j] != '\0')
		{
			if (v_i->map[v.i][v.j] != '0' && v_i->map[v.i][v.j] != '1' && \
			v_i->map[v.i][v.j] != 'C' && v_i->map[v.i][v.j] != 'E' && \
			v_i->map[v.i][v.j] != 'P')
				error("Введена невалидныя карта!\n");
			count_symbol(v_i->map[v.i][v.j], &v.exit, &v.start, &v.thing);
			save_e_c(v_i, &v);
			v.j++;
		}
		v.i++;
	}
	if (v.exit != 1 || v.start != 1 || v.thing < 1)
		error("Введена невалидныя карта!\n");
}

void	validator(t_var_image *var_image)
{
	int	i;

	i = 0;
	check_symbols(var_image);
	check_contour(var_image->map, &var_image->height, &var_image->width);
	while (i < var_image->width)
	{
		if (var_image->map[0][i] != '1' || \
		var_image->map[var_image->height - 1][i] != '1')
			error("Введена невалидныя карта!\n");
		i++;
	}
	i = 0;
	while (i < var_image->height)
	{
		if (var_image->map[i][0] != '1' || \
		var_image->map[i][var_image->width - 1] != '1')
			error("Введена невалидныя карта!\n");
		i++;
	}
}
