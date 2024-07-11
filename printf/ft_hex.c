/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 01:32:05 by spawar            #+#    #+#             */
/*   Updated: 2024/04/11 23:46:02 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned	int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

static int	ft_converter(unsigned int num, const char format)
{
	int	flag;

	flag = 0;
	if (num >= 16)
	{
		flag = ft_converter(num / 16, format);
		if (flag < 0)
			return (-1);
		ft_converter(num % 16, format);
	}
	else
	{
		if (num <= 9)
			flag = ft_putchar((num + '0'));
		else
		{
			if (format == 'x')
				flag = ft_putchar(num + 87);
			else if (format == 'X')
				flag = ft_putchar(num + 55);
		}
	}
	return (flag);
}

int	ft_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
	{
		if (ft_converter(num, format) < 0)
			return (-1);
	}
	return (ft_len(num));
}
