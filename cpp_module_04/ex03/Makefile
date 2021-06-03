NAME		= ex03

SRC			=	main.cpp 		\
				AMateria.cpp	\
				Character.cpp	\
				Cure.cpp		\
				Ground.cpp		\
				Ice.cpp			\
				MateriaSource.cpp

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
