NAME = PmergeMe
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM = rm -rf

SRC = main.cpp PmergeMe.cpp
INCLUDES = PmergeMe.hpp 
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