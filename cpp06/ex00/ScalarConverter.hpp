#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP


# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cstring>
# include <string>
# include <limits>

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	INVALID
};

struct s_data {
    char c;
    double d;
    float f;
    int i;
    bool isCharValid;
    bool isDoubleValid;
    bool isFloatValid;
    bool isIntValid;
};

class ScalarConverter
{
	private:
		ScalarConverter();

		//check.cpp
		static int	checkType(std::string str, s_data *data);
		static bool	isChar(std::string str, s_data *data);
		static bool	isDouble(std::string str, s_data *data);
		static bool	isFloat(std::string str, s_data *data);
		static bool	isInt(std::string str, s_data *data);

		static void	convertChar(s_data *data);
		static void	convertInt(s_data *data);
		static void	convertFloat(s_data *data);
		static void	convertDouble(s_data *data);

	public:
		static void	convert(std::string literal);
};


#endif
