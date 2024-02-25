NAME		= identify

SRC			= Base.cpp \
			functions.cpp \
			main.cpp

OBJ_DIR		= ./objects/
OBJS		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

HEADERS		= Base.hpp \
			A.hpp \
			B.hpp \
			C.hpp \
			header.hpp

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