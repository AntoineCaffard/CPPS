# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaffard <acaffard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:34:02 by acaffard          #+#    #+#              #
#    Updated: 2025/01/07 11:34:31 by acaffard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = claptrap
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp ClapTrap.cpp
INCLUDES = ClapTrap.hpp
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