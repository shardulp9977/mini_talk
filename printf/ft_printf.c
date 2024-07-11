/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 23:18:14 by spawar            #+#    #+#             */
/*   Updated: 2024/04/11 23:28:59 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(va_list types, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(types, int));
	else if (format == 's')
		len += ft_putstr(va_arg(types, char *));
	else if (format == 'p')
		len += ft_putptr(va_arg(types, unsigned long));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(types, int));
	else if (format == 'u')
		len += ft_u(va_arg(types, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_hex(va_arg(types, unsigned int), format);
	else if (format == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	types;
	int		len;

	len = 0;
	va_start(types, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			len += ft_check_format(types, *str);
			if (len < 0)
				return (-1);
		}
		else
		{
			len += ft_putchar(*str);
			if (len < 0)
				return (-1);
		}
		str++;
	}
	va_end(types);
	return (len);
}
