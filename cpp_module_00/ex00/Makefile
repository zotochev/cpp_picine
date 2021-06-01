NAME		= megaphone

SRC			= megaphone.cpp

OBJ			= $(SRC:.cpp=.o)

CXX			= clang++

CXXFLAGS 	:= -Wall -Wextra -Werror


.PHONY		: all clean fclean re
all			: $(NAME)

$(NAME)		: $(OBJ)
			$(CXX) $(CXXFLAGS) $< -o $@

.o			: .cpp

clean		:
			rm -rf $(OBJ)

fclean		:clean
			rm -rf $(NAME)

re			: fclean all
