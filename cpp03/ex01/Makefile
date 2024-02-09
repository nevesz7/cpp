NAME		= scav

SRC			= ClapTrap.cpp \
			ScavTrap.cpp \
			get.cpp	\
			set.cpp \
			main.cpp

OBJ_DIR		= ./objects/
OBJS		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

HEADERS		= ClapTrap.hpp \
			ScavTrap.hpp

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

re:			fclean all

.PHONY:		all clean fclean re