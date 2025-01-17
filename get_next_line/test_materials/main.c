/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:33:46 by yuknakas          #+#    #+#             */
/*   Updated: 2025/01/14 15:17:22 by yuknakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
	int		fd;
	int		line_no = 1;
	char	*line;

	fd = open("text6.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	line = get_next_line(fd);
	while (line_no < 16)
	{
		printf("line %d: %s\n", line_no, line);
		free (line);
		line = get_next_line(fd);
		line_no++;
	}
	return (0);
}
