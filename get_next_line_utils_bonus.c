/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:21:25 by rel-isma          #+#    #+#             */
/*   Updated: 2022/11/08 17:45:30 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	const char	*scpy;
	size_t		len_s;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	len_s = ft_strlen(&s[start]);
	if (len_s < len)
		len = len_s;
	scpy = malloc((len + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	s = s + start;
	i = 0;
	while (s[i] != '\0' && len > 0)
	{
		((char *)scpy)[i] = s[i];
		i++;
		len--;
	}
	((char *)scpy)[i] = '\0';
	return ((char *)scpy);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len_str;
	char	*scpy;

	if (!s1)
		return (NULL);
	len_str = ft_strlen(s1);
	scpy = malloc((len_str + 1) * sizeof(char));
	if (!scpy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*pcat;
	const char	*cat_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	cat_str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!cat_str)
		return (NULL);
	pcat = (char *)cat_str;
	while (*s1)
	{
		*pcat++ = *s1++;
	}
	while (*s2)
	{
		*pcat++ = *s2++;
	}
	*pcat = '\0';
	return ((char *)cat_str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (len >= 0)
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
		len--;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
