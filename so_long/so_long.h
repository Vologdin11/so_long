#ifndef SO_LONG_H
# define SO_LONG_H

//# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);

#endif
