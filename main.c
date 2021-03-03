/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 00:31:25 by aalcara-          #+#    #+#             */
/*   Updated: 2021/03/03 16:59:59 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <fcntl.h> //open
#include <stdio.h> //printf
#include <string.h> //strlen
#include <stdlib.h> //calloc
/*	OPEN

	int open(const char *pathname, int flags);
		O_RDONLY: flag to read only

		return: return the fd used or -1 on error.


*/

int				main(void)
{
	int		fd1;
	char 	*line;
	int		gnl_react;
	int 	n_line = 1;

	fd1 = open("test1.txt", O_RDONLY);
	gnl_react = get_next_line(fd1, &line);
	// printf("\nfd1: %d\t return = %d", fd1, gnl_react);
	while (gnl_react > 0)
	{
		printf("\nline [%d]: %s\nreturn = %d\n---", n_line, line, gnl_react);
		n_line++;
		gnl_react = get_next_line(fd1, &line);
	}
	printf("\nline [%d]: %s\nreturn = %d\n---\n", n_line, line, gnl_react);
	return 0;
}
