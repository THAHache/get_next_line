#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		ft_strchr(const char *s, int c)
{
	int		i;
	char	*aux;

	i = 0;
	aux = (char *)s;
	while (aux[i] != '\0')
	{
		if (aux[i] == c)
			return (i);
		i++;
	}
	if (aux[i] == c)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*dst;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(dst = malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
		return (NULL);
	while (i < len_s1)
	{
		dst[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len_s2)
	{
		dst[len_s1 + i] = s2[i];
		i++;
	}
	dst[len_s1 + i] = '\0';
	free(s1);
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		srclen;

	i = 0;
	srclen = ft_strlen(s1);
	if (!(dst = malloc(ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[i] != '\0' && i < srclen)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (!(dst = malloc(len + 1)))
		return (NULL);
	dst[0] = '\0';
	if (len_s < start)
		return (dst);
	if (start + len > len_s)
		len = len_s - start;
	while (i < len)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}