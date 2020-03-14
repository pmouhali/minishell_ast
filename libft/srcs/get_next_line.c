/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suzie <suzie@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:40:24 by pmouhali          #+#    #+#             */
/*   Updated: 2020/03/14 20:32:24 by suzie            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *ft_strnjoin(char *s1, char const *s2, long n)
{
	long			j;
	char			*new;
	unsigned long	i;

	i = s1 == ((void*)0) ? 0 : ft_strlen(s1);
	j = ft_strlen(s2);
	if (n == -1 || n > j)
		n = j;
	if (!(new = (char*)malloc(sizeof(char) * (i + n + 1))))
		return (NULL);
	if (s1)
	{
		i = -1;
		while (s1[++i] != '\0')
			new[i] = s1[i];
		free(s1);
	}
	j = -1;
	while (j < n && s2[++j] != '\0')
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}

int	get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	int			ret;
	int			i;

	if (!line || fd < 0 || BUFFER_SIZE < 0 || read(fd, buf, 0) == -1)
		return (-1);
	i = ft_index(buf, '\n');
	*line = ft_strnjoin(((void*)0), buf, i);
	ft_memmove(buf, &buf[i + 1], BUFFER_SIZE - i);
	if (i != -1)
		return (1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) != -1)
	{
		buf[ret] = '\0';
		if (ret == 0)
			return (0);
		i = ft_index(buf, '\n');
		*line = ft_strnjoin(*line, buf, i);
		ft_memmove(buf, &buf[i + 1], (i == -1 ? 0 : BUFFER_SIZE - i));
		if (i != -1)
			return (1);
	}
	return (ret);
}
