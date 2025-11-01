# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 20:55:45 by biphuyal          #+#    #+#              #
#    Updated: 2025/11/01 21:42:52 by biphuyal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): server.o
	$(CC) $(CFLAGS) server.o -o $(SERVER)

$(CLIENT): client.o
	$(CC) $(CFLAGS) client.o -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f server.o client.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all