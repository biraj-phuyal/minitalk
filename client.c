/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 00:41:05 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/01 00:44:29 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

static void	ack_handler(int sig, siginfo_t *info, void *useless)
{
	
}

int main(int args, char **argv)
{
	int	pid;
	struct sigaction sa;

	if (args != 3)
		return (write (1, "Usage: ./client [PID] [MESSAGE]\n", 32));
	pid = pid_atoi(argv[1]);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = ack_handler;
	sigemptyset(&sa.sa_mask);
}