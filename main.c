#include "so_long.h"

static void	init_var_img(t_var_image *var_img, char *argv)
{
	var_img->map = read_map(argv);
	var_img->count_subj = 0;
	var_img->count_move = 0;
	var_img->total_subj = 0;
	var_img->mlx = mlx_init();
}

static int	ft_close(void *param)
{
	(void)param;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_var_image	var_img;

	if (argc != 2)
		error("Передайте карту в формате .ber!\n");
	init_var_img(&var_img, argv[1]);
	validator(&var_img);
	var_img.win = mlx_new_window(var_img.mlx, var_img.width * 30, \
	var_img.height * 30, "so_long");
	create_image(var_img);
	mlx_hook(var_img.win, 2, 1L <<0, work_clicks, &var_img);
	mlx_hook(var_img.win, 17, 0, ft_close, NULL);
	mlx_loop(var_img.mlx);
	return (0);
}
