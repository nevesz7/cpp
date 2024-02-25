#include "ScalarConverter.hpp"
#include "header.hpp"

int ScalarConverter::checkType(std::string str, s_data *data)
{
	if (isDouble(str, data))
		return (DOUBLE);
	else if (isFloat(str, data))
		return (FLOAT);
	else if (isInt(str, data))
		return (INT);
	else if (isChar(str, data))
		return (CHAR);
	else
		return (INVALID);
}

bool	ScalarConverter::isDouble(std::string str, s_data *data)
{
	if (str == "inf" || str == "+inf" || str == "-inf" || str == "nan")
	{
		data->isCharValid = false;
		data->isDoubleValid = true;
		data->isFloatValid = true;
		data->isIntValid= false;
		data->d = strToDouble(str);
		return true;
	}

	bool	hasDot = false;
	int i = 0;

	while ((str[i] == '+') || str[i] == '-')
		i++;

	while (str[i])
	{
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			return (false);
		if (str[i] == '.' && hasDot)
			return (false);
		if (str[i] == '.')
			hasDot = true;
		i++;
	}
	if (hasDot)
		data->d = strToDouble(str);
	else 
	{
		double value = std::strtod(str.c_str(), NULL);
		if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		{
			data->d = strToDouble(str);
			return true;
		}
	}
	return (hasDot);
}

bool ScalarConverter::isFloat(std::string str, s_data *data)
{
	if (str == "inff" || str == "+inff" || str == "-inff" || str == "nanf")
	{
		data->isCharValid = false;
		data->isDoubleValid = true;
		data->isFloatValid = true;
		data->isIntValid = false;
		data->f = strToFloat(str);
		return true;
	}
	
	bool	hasDot = false;
	int i = 0;

	while ((str[i] == '+') || str[i] == '-')
		i++;

	while (str[i])
	{
		if (i > 0 && str[i] == 'f')
			break ;
		if (str[i] != '.' && (str[i] < '0' || str[i] > '9'))
			return (false);
		if (str[i] == '.' && hasDot)
			return (false);
		if (str[i] == '.')
			hasDot = true;
		i++;
	}

	double value = std::strtod(str.c_str(), NULL);

	if (str[str.length() - 1] != 'f' 
		|| value > std::numeric_limits<float>::max() 
		|| value < ((std::numeric_limits<float>::max() * -1) - 1))
	{
		return false;
	}
	data->f = strToFloat(str);
	return true;
}

bool ScalarConverter::isInt(std::string str, s_data *data)
{
	int i = 0;

	while ((str[i] == '+') || str[i] == '-')
		i++;

	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9'))
			return (false);
		i++;
	}
	double value = std::strtod(str.c_str(), NULL);

	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		return false;
	data->i = strToInt(str);
	return true;
}

bool ScalarConverter::isChar(std::string str, s_data *data)
{
	if (!((str.length() == 1) && str[0] >= 32 && str[0] < 127))
		return false;
	data->c = strToChar(str);
	return true;
}
