/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madegryc <madegryc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:59:15 by madegryc          #+#    #+#             */
/*   Updated: 2024/01/15 16:10:18 by madegryc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			r;

	line = ft_calloc(1, 1);
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (buffer && line)
	{
		line = ft_strjoin(line, buffer);
		if (ft_line_break(line, buffer))
			return (line);
		r = read(fd, buffer, BUFFER_SIZE);
		if (r < 1)
		{
			free(buffer);
			buffer = NULL;
			if (line[0] != '\0')
				return (line);
			free(line);
			return (NULL);
		}
		buffer[r] = '\0';
	}
	return (NULL);
}
