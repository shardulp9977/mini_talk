/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:14:47 by spawar            #+#    #+#             */
/*   Updated: 2024/04/11 02:07:09 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
	{
		count += ft_putchar('-');
		if (count < 0)
			return (-1);
		count += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		if (count < 0)
			return (-1);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + '0');
	return (count);
}
