NAME		= ex02

SRC			=	main.cpp 			\
				Form.cpp			\
				Bureaucrat.cpp		\
				ShrubberyCreationForm.cpp	\
				RobotomyRequestForm.cpp		\
				PresidentialPardonForm.cpp

OBJ			= $(SRC:.cpp=.o)

CXX			= clang++

CXXFLAGS 	= -Wall -Wextra -Werror

.PHONY		: all clean fclean re
all			: $(NAME)

$(NAME)		: $(OBJ) $(HDRS) Makefile
			$(CXX) $(CXXFLAGS) $(OBJ) -o $@

.o			: .cpp

clean		:
			rm -rf $(OBJ) execution_shrubbery.txt

fclean		: clean
			rm -rf $(NAME)

re			: fclean all
