/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:33:15 by spawar            #+#    #+#             */
/*   Updated: 2024/04/11 01:58:06 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_hex(unsigned int num, const char format);
int		ft_putnbr(int n);
int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putptr(unsigned long long ptr);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
int		ft_u(unsigned int n);

#endif