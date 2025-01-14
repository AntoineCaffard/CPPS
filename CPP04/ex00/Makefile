# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaffard <acaffard@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 13:56:00 by acaffard          #+#    #+#              #
#    Updated: 2025/01/14 12:32:16 by acaffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = CPP04-00
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp
INCLUDES = Animal.hpp Dog.hpp Cat.hpp
OBJS = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(INCLUDES)
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY : all, clean, fclean, re
