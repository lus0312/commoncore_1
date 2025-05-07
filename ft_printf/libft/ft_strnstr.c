/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:32:43 by eulee             #+#    #+#             */
/*   Updated: 2024/10/18 21:34:39 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*substr == '\0')
		return ((char *)str);
	if (len == 0)
		return (0);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == substr[j] && (i + j) < len)
			j++;
		if (substr[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (0);
}
