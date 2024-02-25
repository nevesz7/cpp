#ifndef HEADER_HPP
# define HEADER_HPP

# include "ScalarConverter.hpp"
# include <cstdlib>
# include <cstring>
# include <string>
# include <limits>

//char.cpp
char strToChar(std::string literal);
double charToDouble(char c);
float charToFloat(char c);
int charToInt(char c);

//double.cpp
double strToDouble(std::string literal);
char doubleToChar(double d);
float doubleToFloat(double d);
int doubleToInt(double d);

//float.cpp
float strToFloat(std::string literal);
char floatToChar(float f);
double floatToDouble(float f);
int floatToInt(float f);

//int.cpp
int strToInt(std::string literal);
char intToChar(int i);
double intToDouble(int i);
float intToFloat(int i);

//utils.cpp
int		getPrecision(std::string str);
void	start_data(s_data* data);

#endif
