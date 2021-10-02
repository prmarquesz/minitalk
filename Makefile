# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proberto <proberto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/25 12:12:39 by proberto          #+#    #+#              #
#    Updated: 2021/10/02 17:11:37 by proberto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SRC_SERVER = server.c 
SRC_CLIENT = client.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER):	
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $@

$(CLIENT):	
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $@

clean: 
	rm -f $(SERVER) $(CLIENT)

bonus:	all

re: clean all

PHONY: all clean bonus re xserver xclient
