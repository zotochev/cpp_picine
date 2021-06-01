NAME		= phonebook

SRC			= main.cpp 			\
				Phonebook.cpp	\
				Contact.cpp		\
				utils.cpp

HDRS		= main.hpp			\
				Phonebook.hpp	\
				Contact.hpp		\


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
