#include "so_long.h"

static char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*copy;

	i = 0;
	size = ft_strlen(str) + 1;
	copy = (char *)malloc(size);
	if (copy == NULL)
		return (NULL);
	while (i < size)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strRes;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	strRes = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strRes)
		return (0);
	while (s1[j])
	{
		strRes[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
		strRes[i++] = s2[j++];
	strRes[i] = '\0';
	return (strRes);
}

char	**read_map(char *file_name)
{
	t_var_read	var_read;

	var_read.fd = open(file_name, O_RDONLY);
	if (var_read.fd == -1)
		error("Передан нечитаемый файл!\n");
	var_read.read_byte = read(var_read.fd, var_read.buf, 513);
	while (var_read.read_byte > 0)
	{
		var_read.buf[var_read.read_byte] = '\0';
		if (var_read.res == NULL)
			var_read.res = ft_strdup(var_read.buf);
		else
		{
			var_read.tmp = ft_strjoin(var_read.res, var_read.buf);
			free(var_read.res);
			var_read.res = var_read.tmp;
		}
		var_read.read_byte = read(var_read.fd, var_read.buf, 513);
	}
	var_read.map = ft_split(var_read.res, '\n');
	free(var_read.res);
	return (var_read.map);
}
