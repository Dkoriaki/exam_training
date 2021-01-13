#include <stdlib.h>
#include <unistd.h>
# define BUFFER_SIZE 64

char	*ft_null(void)
{
	char	*ret;
	if (!(ret = (char*)malloc(char)))
		return (NULL);
	ret[0] = '\0';
	return (ret);
}

int		ft_strlen(char *str, int m)
{
	int		i;

	i = 0;
	if (m == 0)
	{
		while (str[i])
			i++;
	}
	if (m == 1)
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	return (i);
}

int		ft_eol(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	len = ft_strlen(s1, 0) + ft_strlen(s2, 0);
	i = 0;
	j = 0;
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}

	}
	if (s2)
	{
		while (s2[j])
		{
			result[i + j] = s2[j];
			j++;
		}
	}
	result[i + j] = '\0';
	return (result);
}

char	*ft_result(char *result, char *buffer, int ret)
{
	char	tmp;

	tmp = result;
	buffer[ret] = '\0';
	result = ft_strjoin(result, buffer);
	free(tmp);
	return (result);
}

int		get_next_line(char **line)
{
	int			ret;
	int			fd;
	static char	*tmp;
	char		*buffer;
	char		*result;

	fd = 0;
	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))) || !line)
		return (-1)
	ret = 0;
	result = (tmp) ? tmp : ft_null;
	if (ft_eol(result) == 0)
	{
		while (ft_eol(result) == 0 && (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
			result = ft_result(result, buffer, ret)
	}
}