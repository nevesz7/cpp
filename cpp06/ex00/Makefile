NAME		= converter

SRC			= ScalarConverter.cpp \
			char.cpp \
			check.cpp \
			double.cpp \
			float.cpp \
			int.cpp \
			utils.cpp \
			main.cpp

OBJ_DIR		= ./objects/
OBJS		= $(SRC:%.cpp=$(OBJ_DIR)/%.o)

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

HEADERS		= ScalarConverter.hpp \
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

run:
	@make re
	@echo "\n\n"
	@echo "No argument test------------------------------------\033[0m"
	./converter  
	@echo "\n\n" 
	
	@echo "Invalid inputs tests--------------------------------" 
	@echo 
	./converter 🌊 
	./converter 🌊🌊
	./converter teste
	./converter "teste"
	./converter 'teste'
	./converter 9f
	./converter 99f
	./converter 0000r
	./converter ' '
	./converter '   '
	./converter '\n'
	./converter '\t'
	./converter '\r'
	./converter '\v'
	./converter '\b'
	./converter '\f'
	./converter '\a'
	./converter '\e'
	./converter '\0'
	./converter '\x0'
	./converter '\x0f'
	./converter " "
	./converter "   "
	@echo "\n\n"
	
	@echo "Limits tests----------------------------------------"
	@echo
	./converter 2147483647
	./converter -2147483648
	./converter 2147483648
	./converter -2147483649
	./converter 340282346638528859811704183484516925440.0f
	./converter -340282346638528859811704183484516925440.0000000000000000f
	./converter 340282446638528859811704183484516925455.9f
	./converter -340282446638528859811704183484516925499.9900000000000000f
	./converter 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
	./converter -179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.0
	./converter 179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9
	./converter -179769313486239570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858399.9
	@echo "\n\n"
	
	@echo "Char tests----------------------------------------"
	@echo
	./converter 'A'
	./converter 'l'
	./converter 'e'
	./converter 'x'
	./converter '/'
	./converter '?'
	./converter ':'
	./converter '%'
	@echo "\n\n"
	
		
	@echo "Integer tests----------------------------------------"
	@echo
	./converter 0
	./converter 1
	./converter -1
	./converter 42
	./converter 65
	./converter 314
	@echo "\n\n"
	
		
	@echo "Float tests----------------------------------------"
	@echo
	./converter 0.0f
	./converter 1.1f
	./converter -1.1f
	./converter 42.42f
	./converter 65.56f
	./converter 3.14f
	@echo "\n\n"

		
	@echo "Double tests----------------------------------------"
	@echo
	./converter 0.0
	./converter 1.1
	./converter -1.1
	./converter 42.42
	./converter 65.56
	./converter 3.14
	@echo "\n\n"



	@echo "Pseudo Literal tests----------------------------------------"
	@echo
	./converter nan
	./converter nanf
	./converter +inf
	./converter -inf
	./converter +inff
	./converter -inff
	@echo "\n\n"

.PHONY:		all clean fclean re