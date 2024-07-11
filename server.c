/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 13:22:30 by spawar            #+#    #+#             */
/*   Updated: 2024/06/17 05:06:39 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	i;
	static char	c;

	if (signum == SIGUSR2)
		c = c | 1 << i;
	i++;
	if (i == 7)
	{
		write(1, &c, 1);
		if (!c)
			write(1, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("The server has started. The PID is %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
