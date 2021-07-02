#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_var_image
{
	int		width;
	int		height;
	int		count_subj;
	int		total_subj;
	int		count_move;
	int		pos_exit_x;
	int		pos_exit_y;
	void	*mlx;
	void	*win;
	char	**map;
}				t_var_image;

typedef struct s_var_map
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		count_fire;
	int		count_water;
	int		count_land;
}				t_var_map;

typedef struct s_sprites
{
	void	*avatar;
	void	*empty;
	void	*wall;
	void	*fire;
	void	*water;
	void	*land;
	void	*out;
}				t_sprites;

typedef struct s_positions
{
	int	player_x;
	int	player_y;
	int	move_pos_x;
	int	move_pos_y;
}				t_position;

typedef struct s_var_read
{
	int		fd;
	int		read_byte;
	char	buf[512];
	char	**map;
	char	*tmp;
	char	*res;
}				t_var_read;

typedef struct s_var_check
{
	int	i;
	int	j;
	int	exit;
	int	start;
	int	thing;
}				t_var_check;

int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
char	**read_map(char *file_name);
void	validator(t_var_image *var_image);
void	error(char *text_error);
void	create_image(t_var_image var_image);
int		work_clicks(int key, t_var_image *var_image);
void	ft_putnbr(int n);
void	check_contour(char **map, int *height, int *width);
void	out_count_move(t_var_image *var);

#endif
