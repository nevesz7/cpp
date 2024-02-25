#include "header.hpp"

int	getPrecision(std::string str)
{
	bool	hasDot = false;
	int precision = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!hasDot && str[i] == '.')
		{
			hasDot = true;
		}
		else if (str[i] && hasDot && str[i] != 'f')
			precision++;
	}
	return ((precision == 0) ? 1 : precision);
}

void start_data(s_data* data)
{
	data->c = 0;
	data->d = 0;
	data->f = 0;
	data->i = 0;
	data->isCharValid = false;
    data->isDoubleValid = false;
    data->isFloatValid = false;
    data->isIntValid = false;
}