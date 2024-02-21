NAME		= bureaucat

SRC			= Bureaucrat.cpp \
			AForm.cpp \
			Intern.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp \
			main.cpp

OBJ_DIR		= ./objects/
OBJS		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

HEADERS		= Bureaucrat.hpp \
			AForm.hpp \
			Intern.hpp \
			PresidentialPardonForm.hpp \
			RobotomyRequestForm.hpp \
			ShrubberyCreationForm.hpp

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
			$(CXX) $(CXXFLAGS) -c $< -o $@ -I .

$(OBJ_DIR):
			mkdir -p $@

clean:		
			rm -rf ./objects/

fclean:		clean
			rm -f $(NAME)
			rm -f trees_shrubbery

re:			fclean all

.PHONY:		all clean fclean re