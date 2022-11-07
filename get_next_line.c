/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:49:17 by rel-isma          #+#    #+#             */
/*   Updated: 2022/11/03 12:03:13 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *help)
{
	int len;
	char *str;

	len = 0;
	if (!help)
		return (NULL);
	if (ft_strchr(help, '\n'))
	{
		while (help[len] != '\n')
			len++;
		str = ft_substr(help, 0, len + 1);
		return (str);
	}
	return (help);
}

char	*ft_line_next(char *help)
{
	int len2;
	char *str2;

	len2 = 0;
	if (!help)
		return (NULL);
	if (ft_strchr(help, '\n'))
	{
		while (help[len2] != '\n')
			len2++;
		str2 = help;
		str2 = ft_strdup(&str2[len2 + 1]);
		free(help);
		return (str2);
	}
	return (NULL);
}

char	*read_file(int fd, char *help)
{
	int 	read_c = 1;
	char 	*tmp;
	char	buf[BUFFER_SIZE + 1];

	while (read_c > 0 && !ft_strchr(help, '\n'))
	{
		read_c = read(fd, buf, BUFFER_SIZE);
		if (read_c <= 0)
			return (NULL);
		buf[read_c] = '\0';
		tmp = help;
		help = ft_strjoin(help, buf);
		free(tmp);
	}
	return (help);
}

char *get_next_line(int fd)
{
	static char	*help;
	char		*line;
	
	if (fd < 0 || read(fd, NULL, 0) < 0)
	{
		free(help);
		help = NULL;
		return (NULL);
	}
	help = read_file(fd, help);
	if (help && !ft_strchr(help, '\n'))	
	{
		line = help;
		help = NULL;
		return (line);
	}
	line = ft_line(help);
	help = ft_line_next(help);
	return (line);
}

#include <fcntl.h>

#include <stdio.h>

int main()
{
    char    *line;
    int fd = open("test", O_RDONLY );
	while ((line = get_next_line(fd)))
    {
		printf("%s", line);
        free(line);
    }
}
