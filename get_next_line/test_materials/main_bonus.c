/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:33:46 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/14 15:17:13 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;
	int		fd5;
	int		fd6;
	int		fd7;
	int		line_no = 1;
	char	*line;

	fd1 = open("text1.txt", O_RDONLY);
	fd2 = open("text2.txt", O_RDONLY);
	fd3 = open("text3.txt", O_RDONLY);
	fd4 = open("text4.txt", O_RDONLY);
	fd5 = open("text5.txt", O_RDONLY);
	fd6 = open("text6.txt", O_RDONLY);
	fd7 = open("text7.txt", O_RDONLY);
	printf("fd3 is \n");
	while (line_no < 16)
	{
		line = get_next_line(fd1);
		printf("File 1 line %d: %s\n", line_no, line);
		free (line);
		line = get_next_line(fd2);
		printf("File 2 line %d: %s\n", line_no, line);
		free (line);
		line = get_next_line(fd3);
		printf("File 3 line %d: %s\n", line_no, line);
		free (line);
		line = get_next_line(fd4);
		printf("File 4 line %d: %s\n", line_no, line);
		free (line);
		line = get_next_line(fd5);
		printf("File 5 line %d: %s\n", line_no, line);
		free (line);
		line = get_next_line(fd6);
		printf("File 6 line %d: %s\n", line_no, line);
		free (line);
		line = get_next_line(fd7);
		printf("File 7 line %d: %s\n", line_no, line);
		free (line);
		printf("---------------------------------\n");
		line_no++;
	}
	return (0);
}
