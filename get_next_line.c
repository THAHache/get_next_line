#include "get_next_line.h"

/*
** en put_line se recorre la variable auxiliar y si tiene salto de línea 
** guarda en line hasta el salto de línea. 
** El sobrante se guardará de nuevo en la variable estática para volver a usarlo
** en la siguiente llamada a la función.
*/ 


/*int put_line1(int fd, char **line, char *aux)
{
	char	*tmp;
	int		flag;
	int		pos;

	if (!(tmp = malloc(sizeof(char *) * (ft_strlen(aux) + 1))))
		return (-1);
		//printf("aux5: %s\n\n", aux);
	if((pos = ft_strchr(aux, '\n')) >= 0)
	{
		*if (!(tmp = malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
		return (-1);/
		 
		*line = ft_substr(aux, 0, pos);
		
		tmp = aux;
		//free (aux);
		aux = ft_substr(tmp, pos + 1, ft_strlen(aux));
		flag = 1;
		//printf("aux3: %s\n\n", aux);
		//free (tmp);
		//char	*ft_substr(char const *s, unsigned int start, size_t len)
	}
	else
	{
		*line = aux;
		//printf("aux4: %s\n\n", aux);
		//printf("line4: %s\n\n", *line);
		free(aux);
		flag = 0;
	}
	free (tmp);
	//printf("line6: %s\n\n", *line);
	return (flag);
}*/

int put_line(char **line, char **aux)
{
	char	*tmp;
	int		flag;
	int		pos;

	if (!(tmp = malloc(sizeof(char *) * (ft_strlen(*aux) + 1))))
		return (-1);
	if((pos = ft_strchr(*aux, '\n')) >= 0)
	{
		*line = ft_substr(*aux, 0, pos);
		
		tmp = *aux;
		*aux = ft_substr(tmp, pos + 1, ft_strlen(tmp));
		flag = 1;
	}
	else
	{
		*line = *aux;
		*aux = NULL;
		free(*aux);
		flag = 0;
	}
	free (tmp);
	return (flag);
}


/*int	get_next_line(int fd, char **line)
{
	static char	*aux[4096];
	//char		*buff;
	char buff[BUFFER_SIZE + 1];
	size_t		reader;
	int			ctrl;

	//printf("fd: %i\nBS: %i\n", fd, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	//printf("hola\n");
	/if (!(buff = malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
		return (-1);*
	if (!aux[fd])
		aux[fd] = ft_strdup("");

	//printf("aux9: %s\n\n", aux[fd]);
	//while (((reader = read (fd, buff, BUFFER_SIZE)) > 0) && ((ft_strchr(buff, '\n')) == -1))
	while (((ft_strchr(aux[fd], 10)) == -1) && ((reader = read (fd, buff, BUFFER_SIZE)) > 0))
	//while (((ft_strchr(buff, '\n')) == -1) && ((reader = read (fd, buff, BUFFER_SIZE)) > 0))
	{
		//printf("nl: %i\n", ft_strchr(buff, 10));
		buff[reader] = '\0';
		aux[fd] = ft_strjoin(aux[fd], buff);
		//printf("reader: %zu\n\n", reader);
	}
	//printf("aux1: %s\n\n", aux[fd]);
	//aux[fd] = ft_strjoin(aux[fd], buff);
	//printf("aux2: %s\n\n", aux[fd]);
	//printf("aux: %s\n\n", aux[fd]);
	ctrl = put_line(line, &aux[fd]);
	//ctrl = put_line(fd, line, aux[fd]);
	//ctrl = 0;
	//free(buff);
		//line = aux[fd];
	//printf("llega aux: %s\n\n", aux[fd]);
	return (ctrl);
}*/

/*int			ft_free(char **line, char **tmp)
{
	*line = *tmp;
	*tmp = NULL;
	free(*tmp);
	return (0);
}*/

int	get_next_line(int fd, char **line)
{
	static char	*aux[4096];
	char		*buff;
	int		reader;
	int			ctrl;

	/*
	** test falla cuando fd == 42
	*/
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buff = malloc(sizeof(char *) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!aux[fd])
		aux[fd] = ft_strdup("");

	while (((ft_strchr(aux[fd], '\n')) == -1) && ((reader = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[reader] = '\0';
		aux[fd] = ft_strjoin(aux[fd], buff);
	}
	if (reader == -1)
	{
		ctrl = -1;
		/*if ((ft_free(line, &aux[fd])) == 0)
			return (-1);
		*line = aux[fd];
		aux[fd] = NULL;
		free(aux);/*/
		//return (-1);
	}
	else
		ctrl = put_line(line, &aux[fd]);
	free(buff);
	return (ctrl);
}