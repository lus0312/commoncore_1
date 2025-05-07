/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:23:30 by eulee             #+#    #+#             */
/*   Updated: 2024/10/30 20:20:02 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		len;
	char	nbr;

	len = 0;
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	else if (n < 0)
	{
		len += write(fd, "-", 1);
		n *= -1;
	}	
	if (n >= 10)
		len += ft_putnbr_fd(n / 10, 1);
	nbr = n % 10 + '0';
	len += write(fd, &nbr, 1);
	return (len);
}
