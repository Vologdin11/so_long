#include "so_long.h"

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

void	error(char *text_error)
{
	ft_putstr(text_error);
	exit(EXIT_FAILURE);
}

void	ft_putnbr(int n)
{
	char	tmp;
	long	i;

	i = n;
	if (i < 0)
	{
		write(1, "-", 1);
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		tmp = (i % 10) + '0';
		write(1, &tmp, 1);
	}
	else
	{
		tmp = i + '0';
		write(1, &tmp, 1);
	}
}

void	check_contour(char **map, int *height, int *width)
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
