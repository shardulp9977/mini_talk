/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spawar <spawar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:25:55 by spawar            #+#    #+#             */
/*   Updated: 2024/07/11 17:26:39 by spawar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char *c)
{
	int	i;
	int	j;
	int	k;

	j = ft_strlen(c);
	k = 0;
	while (k <= j)
	{
		i = 0;
		while (i < 7)
		{
			if ((c[k] >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i++;
			usleep(100);
		}
		k++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*c;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		c = argv[2];
		ft_send(pid, c);
	}
	return (0);
}
