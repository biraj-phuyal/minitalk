/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:46:34 by biphuyal          #+#    #+#             */
/*   Updated: 2025/07/17 12:50:24 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_data
{
	unsigned char c;
	int bits;
	pid_t client_pid;
}			t_data;

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

#endif
