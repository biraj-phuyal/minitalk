/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:12:24 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/03 17:17:37 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <errno.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>

void			ft_putnbr(long pid);
int				pid_atoi(char *argv);
void			ft_putstr(unsigned char *str);
void			*ft_calloc(size_t nmemb, size_t size);
unsigned char	*ft_strjoin(unsigned char *s1, char c);

#endif