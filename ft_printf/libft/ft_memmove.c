/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:38:10 by eulee             #+#    #+#             */
/*   Updated: 2024/10/20 19:14:31 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	void	*result;

	result = dest;
	if (dest == src || count == 0)
		return (result);
	else if (dest < src)
	{
		while (count-- > 0)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	}
	else
	{
		while (count-- > 0)
			*(unsigned char *)(dest + count) = *(unsigned char *)(src + count);
	}
	return (result);
}
