/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uttil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:06:18 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/03 17:17:44 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(long pid)
{
	char	character;

	if (pid >= 10)
		ft_putnbr(pid / 10);
	character = '0' + (pid % 10);
	write(1, &character, 1);
}

void	ft_putstr(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	total_size = nmemb * size;
	if (nmemb != 0 && size != total_size / nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

unsigned char	*ft_strjoin(unsigned char *s1, char c)
{
	size_t			i;
	size_t			j;
	size_t			total_length;
	unsigned char	*string;

	j = 0;
	total_length = 0;
	while (s1[total_length])
		total_length++;
	string = (unsigned char *)malloc(total_length + 2);
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
