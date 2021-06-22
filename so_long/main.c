#include "so_long.h"
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

static void	ft_putstr(char *str)
{
	write(2, str, ft_strlen(str));
}

static void	error(char *text_error)
{
	ft_putstr(text_error);
	exit(EXIT_FAILURE);
}

static char	**read_map(char *file_name)
{
	int		fd;
	int		read_byte;
	char	buf[512];
	char	**map;
	char	*tmp;
	char	*res;

	fd = open(file_name, O_RDONLY);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buf, 513);
		buf[read_byte] = '\0';
		if (res == NULL)
			res = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(res, buf);
			res = tmp;
			free(tmp);
		}
	}
	map = ft_split(res, '\n');
	return (map);
}

static void	count_symbol(char c, int *exit, int *start, int *thing)
{
	if (c == 'E')
		(*exit)++;
	else if (c == 'P')
		(*start)++;
	else if (c == 'C')
		(*thing)++;
}

static void	check_symbols(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	start;
	int	thing;

	i = 0;
	exit = 0;
	start = 0;
	thing = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'C' && \
			map[i][j] != 'E' && map[i][j] != 'P')
				error("Введена невалидныя карта!\n");
			count_symbol(map[i][j], &exit, &start, &thing);
			j++;
		}
		i++;
	}
	if (exit != 1 || start != 1 || thing < 1)
		error("Введена невалидныя карта!\n");
}

static void	check_contour(char **map, int *height, int *width)
{
	int	general_width;

	*height = 0;
	general_width = 0;
	while (map[*height] != NULL)
	{
		*width = 0;
		while (map[*height][*width] != '\0')
			(*width)++;
		if (general_width == 0)
			general_width = *width;
		else if (*width != general_width)
			error("Указан неверный размер карты!\n");
		(*height)++;
	}
	if (*height >= general_width)
		error("Указан неверный размер карты!\n");
}

static void	validator(char **map)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	check_symbols(map);
	check_contour(map, &height, &width);
	while (i < width )
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			error("Введена невалидныя карта!\n");
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			error("Введена невалидныя карта!\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
		error("Передайте карту в формате .ber!\n");
	map = read_map(argv[1]);
	validator(map);
	return (0);
}
