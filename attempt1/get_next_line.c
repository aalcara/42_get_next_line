/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:56 by aalcara-          #+#    #+#             */
/*   Updated: 2021/02/26 00:44:46 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//

int				get_next_line(int fd, char **line)
{
	static int		new_line = 0;
	int 			i;
	char			*ffile;
	int				errx;
	int				old_line;
	
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	i = new_line;
	printf("\n25:\ti = %d\tnew_line = %d\tfd = %d", i, new_line, fd);//
	if (!(ffile = (char *)ft_calloc(200, sizeof(char)))) //definir tamanho do calloc
	{
		printf("\n28:\tERRO AO CHAMAR CALLOC!!");//
		return (-1);
	}
	if ((errx = read(fd, ffile, BUFFER_SIZE)) <= 0)
	{
		printf("\n31:\tERRO AO LER O FD!!\t errx = %d", errx);//
		return (-1);
	}
	printf("\n37:\terrx = %d", errx);//
	while (ffile[i] != '\n' && ffile[i] != '\0')
	{
		i++;
	}
	if ( i > new_line)
	{
		printf("\n44:\tcriando new line\ti = %d", i);//
		*line = ft_substr(ffile, new_line, (i - new_line));
		old_line = new_line;
		new_line = i + 1;
		free(ffile);
		return (i - old_line);
	}
	return (0);
}
