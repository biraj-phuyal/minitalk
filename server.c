/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:27:18 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/03 18:08:27 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handler(int sig, siginfo_t *info, void *useless)
{
	static unsigned char	c;
	static int				i;
	static unsigned char	*string;

	(void)useless;
	if (!string)
		string = ft_calloc(sizeof(unsigned char), 1);
	if (!string)
		return ;
	if (sig == SIGUSR1)
		c |= (1 << i);
	if (++i == 8)
	{
		if (c == '\0')
		{
			ft_putstr(string);
			string = NULL;
			kill(info->si_pid, SIGUSR2);
		}
		else
			string = ft_strjoin(string, c);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
