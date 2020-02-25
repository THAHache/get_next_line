#ifndef LIBGNL_H

# define LIBGNL_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

//# include <crtype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s, char const *s2);
char	*ft_strdup(const char *s);
int		get_next_line(int fd, char **line);

#endif