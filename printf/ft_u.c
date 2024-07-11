/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 01:47:19 by spawar            #+#    #+#             */
/*   Updated: 2024/04/11 02:09:23 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_u(unsigned int n)
{
	int		count;

	count = 0;
	if (n >= 10)
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
