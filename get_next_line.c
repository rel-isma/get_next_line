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

char *get_next_line(int fd)
{
	static char *help;
	char buf[BUFFER_SIZE + 1];
    char *tmp;
	char	*line;
	int	read_c;
	int len = 0;
	
	if (fd < 0)
		return (NULL);
	while ((read_c = read(fd, buf, BUFFER_SIZE)) > 0 && ft_strchr(help, '\n') == '\0')
	{
		buf[read_c] = '\0';
		tmp = help;
		help = ft_strjoin(help, buf);
		free(tmp);
	}
	if (read_c < 0)
        return(NULL);
	if (read_c == 0 && !help)
		help = NULL;
	if (*help && !ft_strchr(help, '\n'))
	{
		line = help;
		help = NULL;
		return (line);
	}
	if (ft_strchr(help, '\n'))
	{
		while (buf[len] != '\n')
			len++;
		tmp = help;
		line = ft_substr(buf, 0, len);
		help = ft_strdup(tmp + len + 1);
		free(tmp);
	}
	return (NULL);
}
