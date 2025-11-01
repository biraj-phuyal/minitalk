/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:41:05 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/01 21:42:22 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

static volatile sig_atomic_t	g_ack = 0;

void	handle_sig(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
	else if (sig == SIGUSR2)
		write(1, "Message received", 15);
}

int	pid_atoi(char *argv)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	while (argv[i])
	{
		if (!(argv[i] >= '0' && argv[i] <= '9'))
			exit(write(1, "PID are only made of numbers", 28));
		i++;
	}
	i = 0;
	while (argv[i] >= '0' && argv[i] <= '9')
	{
		pid = pid * 10 + (argv[i] - '0');
		i++;
	}
	return (pid);
}

int	send_bits(int pid, char character)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		g_ack = 0;
		if (character & (1 << bits))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			usleep(42);
		bits++;
	}
	return (0);
}

int	main(int args, char **argv)
{
	int	pid;
	int	i;

	if (args != 3)
		exit(write (1, "Need both the PID and message\n", 30));
	pid = pid_atoi(argv[1]);
	if (pid < 1)
		exit(write (1, "PID must be > 0\n", 16));
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	i = 0;
	while (argv[2][i])
	{
		send_bits(pid, argv[2][i]);
		i++;
	}
	send_bits(pid, '\0');
	return (0);
}
