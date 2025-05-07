/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:36:26 by eulee             #+#    #+#             */
/*   Updated: 2024/11/20 16:40:06 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <fcntl.h>	
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*read_line(int fd, char *buffer, char *backup);

char	*extract_line(char	*backup);

char	*update_backup(char *backup);

char	*gnl_strjoin(char *s1, char *s2);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strchr(const char *str, int c);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	ft_strlen(const char *str);

#endif
