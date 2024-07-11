/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:28:08 by spawar            #+#    #+#             */
/*   Updated: 2024/04/11 01:54:07 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	i = 0;
	if (!s)
		return (write (1, "(null)", 6));
	len = ft_strlen(s);
	while (i < len)
	{
		if (write (1, (s + i), 1) < 0)
			return (-1);
		i++;
	}
	return (len);
}
