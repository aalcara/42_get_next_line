/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:30:56 by aalcara-          #+#    #+#             */
/*   Updated: 2021/02/26 15:51:50 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>//

int				get_next_line(int fd, char **line)
{
	static char		buffer = NULL;
	int				i;
	char			*ffile;
	int				errx;
	int				old_line;
	
	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	

}
