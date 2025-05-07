/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:56:19 by eulee             #+#    #+#             */
/*   Updated: 2024/10/20 19:28:49 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	size_t	i;
	size_t	len;
	char	*arr;

	i = 0;
	len = ft_strlen(string);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		return (0);
	else
	{
		while (i < len)
		{
			arr[i] = string[i];
			i++;
		}
		arr[i] = '\0';
	}
	return (arr);
}
