/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 00:31:25 by aalcara-          #+#    #+#             */
/*   Updated: 2021/02/25 14:16:00 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <fcntl.h> //open
#include <stdio.h> //printf
/*	OPEN

	int open(const char *pathname, int flags);
		O_RDONLY: flag to read only
		
		return: return the fd used or -1 on error.
		

*/

int				main(void)
{
	int		fd1;

	fd1 = open("teste.txt", O_RDONLY);
	printf("teste, fd1 = %d", fd1);
	

	
	
}