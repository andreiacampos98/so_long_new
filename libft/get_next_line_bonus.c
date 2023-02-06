/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:09:25 by anaraujo          #+#    #+#             */
/*   Updated: 2023/01/28 12:34:07 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	str_null(char *str)
{
	str = malloc(1 * sizeof(char));
	str[0] = '\0';
}

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		bytes;

	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(str, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		line[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_str_without_line(char *str)
{
	int		i;
	int		j;
	char	*str_without_line;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	str_without_line = malloc((ft_strlen(str) - i + 1) * sizeof(char));
	if (!str_without_line)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		str_without_line[j++] = str[i++];
	str_without_line[j] = '\0';
	free(str);
	return (str_without_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!str[fd])
	{
		str[fd] = malloc(1 * sizeof(char));
		str[fd][0] = '\0';
	}
	str[fd] = ft_read(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_line(str[fd]);
	str[fd] = ft_str_without_line (str[fd]);
	return (line);
}

/*int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("teste", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}*/