NAME = ex02
CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = tests.cpp Account.cpp
OBJS = $(SRC:.cpp=.o)
INCLUDES = Account.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c $(INCLUDES)
	$(CXX) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all, clean, fclean, re