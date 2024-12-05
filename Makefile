# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: potero-d <potero-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 12:17:44 by potero-d          #+#    #+#              #
#    Updated: 2024/12/05 13:03:35 by potero-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = src/main.cpp src/Game.cpp

CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra 
#LDFLAGS =-Llibs/glew/lib -lGLEW -lGLU -lglfw -lGL -lX11 -lXrandr -lpthread -ldl -Wl,-rpath=libs/glew/lib
SRC_DIR = src


OBJECTS=$(SOURCES:.cpp=.o)

NAME=npuzzle

RM = rm -f

all: $(SOURCES) $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)
	
.cpp.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS)
		
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re