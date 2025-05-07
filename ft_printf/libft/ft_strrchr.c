/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:41:45 by eulee             #+#    #+#             */
/*   Updated: 2024/10/20 19:29:51 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;

	i = ft_strlen(str);
	if (c == '\0')
		return ((char *)str + i);
	while (i > 0)
	{
		if (str[i - 1] == (char)c)
			return ((char *)str + i - 1);
		i--;
	}
	return (0);
}
