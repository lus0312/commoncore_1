/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:01:03 by eulee             #+#    #+#             */
/*   Updated: 2024/11/13 10:13:17 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(char type, va_list ap)
{
	if (type == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (type == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (type == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (type == 'u')
		return (ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hexa(va_arg(ap, unsigned int), type));
	else if (type == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		conversion_check;

	len = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			conversion_check = ft_conversion(*str, ap);
			if (conversion_check == -1)
			{
				va_end(ap);
				return (-1);
			}
			len += conversion_check;
		}
		else
			len += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(ap);
	return (len);
}
