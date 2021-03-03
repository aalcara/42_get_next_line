/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:56 by aalcara-          #+#    #+#             */
/*   Updated: 2021/03/02 21:51:53 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//
#include BUFFER_SIZE=1//todo remover

int				has_new_line(char *marker)
{
	int			i;

	i = 0;
	if (!marker)
		return (0);
	while (marker[i] != '\0')
	{
		if (marker[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		*buffer = NULL;
	char			*marker;
	int				read_return; //* RETURN (1 if ok| 0 if EOF reached| -1 if ERROR)

	read_return = 1;
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while (read_return != 0 && !has_new_line(marker))
	{
		marker = (char *)ft_calloc(sizeof(char) * (BUFFER_SIZE + 1));
		read_return = read(fd, marker, BUFFER_SIZE);
		if ((read_return = read(fd, marker, BUFFER_SIZE)) == -1)
		{
			free(marker);
			return (-1);
		}
		buffer = ft_strjoin(buffer, marker);
	}
	free(marker);
	*line = //todo= fazer algo que retorne a primeira linha do buffer.
	buffer = //todo= Função que retorne o próprio buffer sem a primeira linha (verificar condição da última linha (sem \n no final)).
	//! retornar read_return (0 ou 1)

}
