/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:25:23 by eulee             #+#    #+#             */
/*   Updated: 2024/11/29 16:39:01 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{

    char *line;
    int fd;
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) 
    {
        perror("Failed to open file");
        return (1);
    }
    line = NULL; 	
    while ((line = get_next_line(fd)) != NULL)
    {
    	printf("%s", line);
        free(line);         
    }
    close(fd);
    return (0);
}
