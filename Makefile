# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 20:55:45 by biphuyal          #+#    #+#              #
#    Updated: 2025/11/03 17:12:47 by biphuyal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SRC = uttil.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): server.o $(SRC)
	$(CC) $(CFLAGS) server.o $(SRC) -o $(SERVER)

$(CLIENT): client.o $(SRC)
	$(CC) $(CFLAGS) client.o $(SRC) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f server.o client.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all