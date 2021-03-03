/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:56 by aalcara-          #+#    #+#             */
/*   Updated: 2021/03/03 15:52:13 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//!remover

char			*first_line(char *buffer)
{
	int			i;
	char		*line;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!(line = ft_substr(buffer, 0, i)))
		return (0);
	// printf("28: line = %s", line); //!remover
	return (line);
}

char			*new_buffer(char *buffer)
{
	int			i;
	char		*new_buff;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	if (!(new_buff = ft_substr(buffer, i + 1, ft_strlen(buffer))))
		{
			free(buffer);
			return (0);
		}
	free(buffer);
	return (new_buff);
}

int				has_new_line(char *marker)
{
	int			i;

	i = 0;
	if (!marker)
		return (0);
	while (marker[i])
	{
		if (marker[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*buffer;
	char			*marker;
	int				read_return; //* RETURN (1 if ok| 0 if EOF reached| -1 if ERROR)

	read_return = 1;
	// printf("79: teste\n"); //!remover
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
	{ //!remover
		printf("82: ERRO NOS DADOS INSERIDOS\n"); //!remover
		return (-1);
	} //!remover
	if (!(marker = (char *)ft_calloc(sizeof(char), (BUFFER_SIZE + 1))))
	{ //!remover
		printf("87: ERRO CALLOC\n"); //!remover
		return (-1);
	} //!remover
	// printf("90: ...running... read_return = %d, marker = %s, has_new_line(marker) = %d\n", read_return, marker, has_new_line(marker)); //!remover
	while (read_return != 0 && !has_new_line(marker))
	{
		// printf("96: start while read_return = %d, buffer = %s\n", read_return, buffer); //!remover
		if ((read_return = read(fd, marker, BUFFER_SIZE)) == -1)
		{
			free(marker);
			// printf("96: read return -1\n"); //!remover
			return (-1);
		}
		marker[read_return] = '\0';
		// printf("\n100: end while buffer = %s, marker = %s\n", buffer, marker); //!remover
		buffer = ft_strjoin(buffer, marker);
		// printf("102: end while read_return = %d, buffer = %s\n", read_return, buffer); //!remover
	}
	free(marker);
	// printf("\n\n105: free marker --- buffer = %s, marker = %s", buffer, marker); //!remover
	*line = first_line(buffer);//*função que retorne a primeira linha do buffer.
	// printf("\n107: line = %s", *line); //!remover
	buffer = new_buffer(buffer);//*retorne o próprio buffer sem a primeira linha (verificar condição da última linha (sem \n no final)).
	// printf("\n109: buffer = %s\n", buffer); //!remover
	if (read_return == 0 && ft_strlen(buffer) == 0)
		return (0);
	return (1);
}
