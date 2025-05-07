/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eulee <eulee@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:31:40 by eulee             #+#    #+#             */
/*   Updated: 2024/10/15 14:21:37 by eulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	result;
	int	cnt;

	cnt = 1;
	result = 0;
	while (*str == 32 || (*str >= 8 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			cnt *= -1;
		str++;
	}
	if (*str >= '0' && *str <= '9')
	{
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			str++;
		}
		return (cnt * result);
	}
	else
		return (0);
}
