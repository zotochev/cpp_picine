NAME		= ex02

SRC			= main.cpp
 
HDRS		= Array.hpp 
 
OBJ			= $(SRC:.cpp=.o)

CXX			= clang++

CXXFLAGS 	= -Wall -Wextra -Werror

.PHONY		: all clean fclean re
all			: $(NAME)

$(NAME)		: $(OBJ) $(HDRS)
			$(CXX) $(CXXFLAGS) $(OBJ) -o $@

.o			: .cpp $(HDRS) 

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME)

re			: fclean all
