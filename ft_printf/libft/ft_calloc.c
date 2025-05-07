/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:18:09 by eulee             #+#    #+#             */
/*   Updated: 2024/10/19 22:17:21 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void			*arr;

	if (num != 0 && size > (size_t)-1 / num)
		return (0);
	arr = (void *)malloc(num * size);
	if (!arr)
		return (0);
	else
		ft_memset(arr, 0, num * size);
	return (arr);
}
