#include "ScalarConverter.hpp"
#include "header.hpp"

std::ostream &operator<<(std::ostream &out, s_data data)
{
	out << "char: ";

	if (!data.isCharValid)
	{
		out << "impossible";
	} else if (data.c == 0) {
		out << "Non displayable"; 
	} else {
		out << "'" << data.c << "'";
	}

	out << std::endl << "int: ";
	
	if (!data.isIntValid)
	{
		out << "impossible";
	} else {
		out << data.i;
	}

	out << std::endl << "float: ";
	
	if (!data.isFloatValid)
	{
		out << "impossible";
	} else {
		out << std::fixed << data.f << "f";
	}

	out << std::endl << "double: ";

	if (!data.isDoubleValid)
	{
		out << "impossible";
	} else {
	 	out << std::fixed << data.d;
	}

	out << std::endl;
	return out;
}

void	ScalarConverter::convert(std::string literal)
{
	s_data	data;
	start_data(&data);
	int type = checkType(literal, &data);

	switch (type)
	{
	case CHAR:
		data.isCharValid = true;
		convertChar(&data);
		break ;
	case INT:
		data.isIntValid = true;
		convertInt(&data);
		break ;
	case FLOAT:
		data.isFloatValid = true;
		convertFloat(&data);
		break ;
	case DOUBLE:
		data.isDoubleValid = true;
		convertDouble(&data);
		break ;
	case INVALID:
		std::cerr << "Invalid Input. Please insert a valid Char, Double, Float or Int." << std::endl;
		exit (0);
	}
	std::cout << data << std::endl;
}

void	ScalarConverter::convertChar(s_data *data)
{
	data->isDoubleValid = true;
	data->isFloatValid = true;
	data->isIntValid = true;
	data->d = charToDouble(data->c);
	data->f = charToFloat(data->c);
	data->i = charToInt(data->c);
}

void	ScalarConverter::convertInt(s_data *data)
{
	data->isDoubleValid = true;
	data->isFloatValid = true;

	if (data->i < 0 || data->i > 127)
		data->isCharValid = false;
	else
		data->isCharValid = true;
	
	data->c = intToChar(data->i);
	data->d = intToDouble(data->i);
	data->f = intToFloat(data->i);
}

void	ScalarConverter::convertFloat(s_data *data)
{
	if (data->f == std::numeric_limits<float>::infinity() || 
    data->f == -std::numeric_limits<float>::infinity() || 
    data->f != data->f)
	{
		data->isCharValid = false;
		data->isDoubleValid = true;
		data->isFloatValid = true;
		data->isIntValid = false;
		data->d = floatToDouble(data->f);
		return ;
	}
	data->isDoubleValid = true;

	if (data->f < 0 || data->f > 127)
		data->isCharValid = false;
	else
		data->isCharValid = true;

	if (data->f > std::numeric_limits<int>::max() || data->f < std::numeric_limits<int>::min())
		data->isIntValid = false;
	else
		data->isIntValid = true;

	data->c = floatToChar(data->f);
	data->d = floatToDouble(data->f);
	data->i = floatToInt(data->f);
}

void	ScalarConverter::convertDouble(s_data *data)
{
	if (data->d == std::numeric_limits<double>::infinity() || 
    data->d == -std::numeric_limits<double>::infinity() || 
    data->d != data->d)
	{
		data->isCharValid = false;
		data->isDoubleValid = true;
		data->isFloatValid = true;
		data->isIntValid = false;
		data->f = doubleToFloat(data->d);
		return ;
	}	
	if (data->d < 0 || data->d > 127)
		data->isCharValid = false;
	else
		data->isCharValid = true;

	if (data->d > std::numeric_limits<float>::max() || data->d < (((std::numeric_limits<float>::max()) * -1) - 1))
		data->isFloatValid = false;
	else
		data->isFloatValid = true;

	if (data->d > std::numeric_limits<int>::max() || data->d < std::numeric_limits<int>::min())
		data->isIntValid = false;
	else
		data->isIntValid = true;

	data->c = doubleToChar(data->d);
	data->f = doubleToFloat(data->d);
	data->i = doubleToInt(data->d);
}
