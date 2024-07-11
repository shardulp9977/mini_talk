/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:19:03 by spawar            #+#    #+#             */
/*   Updated: 2024/04/11 23:47:09 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned long long num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

static void	ft_converter(unsigned long long num)
{
	if (num >= 16)
	{
		ft_converter(num / 16);
		ft_converter(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar((num + '0'));
		else
			ft_putchar(num + 87);
	}
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = write(1, "0x", 2);
	if (len < 0)
		return (len);
	ft_converter(ptr);
	len += ft_len(ptr);
	return (len);
}
