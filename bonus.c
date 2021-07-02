#include "so_long.h"

static int	ft_numSize(long n)
{
	int	size;

	if (n < 0)
	{
		n *= -1;
		size = 2;
	}
	else
		size = 1;
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static void	ft_convInt(long num, char *res, int numSize, int n)
{
	res[numSize--] = '\0';
	if (n < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		res[numSize--] = (num % 10) + '0';
		num /= 10;
	}
}

static char	*ft_itoa(int n)
{
	int		numSize;
	long	num;
	char	*res;

	numSize = ft_numSize(n);
	num = n;
	res = (char *)malloc(sizeof(char) * numSize + 1);
	if (!res)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	ft_convInt(num, res, numSize, n);
	return (res);
}

void	out_count_move(t_var_image *var)
{
	char	*count_move;

	count_move = ft_itoa(var->count_move);
	if (count_move == NULL)
		error("Произошла ошибка!\n");
	mlx_string_put(var->mlx, var->win, 5, 5, 0x000000, count_move);
	free(count_move);
}
