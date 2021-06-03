NAME		= ex02

SRC			=	main.cpp 				\
				AssaultTerminator.cpp	\
				Squad.cpp				\
				TacticalMarine.cpp

OBJ			= $(SRC:.cpp=.o)

CXX			= clang++

CXXFLAGS 	= -Wall -Wextra -Werror

.PHONY		: all clean fclean re
all			: $(NAME)

$(NAME)		: $(OBJ) $(HDRS) Makefile
			$(CXX) $(CXXFLAGS) $(OBJ) -o $@

.o			: .cpp

clean		:
			rm -rf $(OBJ)

fclean		: clean
			rm -rf $(NAME)

re			: fclean all
