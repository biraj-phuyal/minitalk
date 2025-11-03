/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 18:27:18 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/03 00:33:39 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void	ft_putnbr(long pid)
{
	char	character;

	if (pid >= 10)
		ft_putnbr(pid / 10);
	character = '0' + (pid % 10);
	write(1, &character, 1);
}

char	*ft_strjoin(char *s1, char c)
{
	size_t		i;
	size_t		j;
	size_t		total_length;
	char		*string;

	j = 0;
	total_length = 0;
	while (s1[total_length])
		total_length++;
	string = (char *)malloc(total_length + 2);
	if (!string)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = c;
	string[i + 1] = '\0';
	free(s1);
	return (string);
}

void	ft_puttr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	write(1, "\n", 1);
}

static void	handler(int sig, siginfo_t *info, void *useless)
{
	static char	c;
	static int	i;
	static char	*string;

	(void)useless;
	if (!string)
		string = calloc(sizeof(char), 1);
	if (!string)
		return ;
	if (sig == SIGUSR1)
		c += (1 << i);
	if (++i == 8)
	{
		if (c == '\0')
		{
			ft_puttr(string);
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
