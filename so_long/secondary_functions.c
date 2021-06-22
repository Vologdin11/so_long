#include "so_long.h"

char	*ft_strdup(const char *str)
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

char	*ft_strjoin(char const *s1, char const *s2)
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
