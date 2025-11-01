/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:27:18 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/31 18:44:08 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putnbr(long pid)
{
	char character;

	if (pid >= 10)
		ft_putnbr(pid / 10);
	character = '0' + (pid % 10);
	write(1, &character, 1);
}

static void	handler(int sig, siginfo_t *info, void *useless)
{
	
}

int main(void)
{
	struct sigaction sa;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
}