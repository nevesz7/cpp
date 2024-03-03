#include "BitcoinExchange.hpp"

// =========== CONSTRUCTORS AND DESTRUCTORS ===========

BitcoinExchange::BitcoinExchange(void)
{
	// std::cout << "Default BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	// std::cout << "Copy BitcoinExchange constructor called" << std::endl;
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	// std::cout << "Copy BitcoinExchange assignation called" << std::endl;
	if (this != &rhs)
	{
		this->db = rhs.getDatabase();
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << "Destructor for BitcoinExchange called" << std::endl;
}

// =========== Read input file, search the database, execute the conversion and print the result ===========

bool checkInputHeader(std::string const &header) {
	return (header == "date | value");
}

void BitcoinExchange::readInputLine(std::string const &line) {
	size_t		pipe;
	std::string	date, value;

	pipe = line.find('|');
	if (pipe == std::string::npos)
		throw (std::runtime_error("bad input => " + line));
	date = line.substr(0, pipe - 1);
	value = line.substr(pipe + 2);
	if (!isValidDate(date)) 
		std::runtime_error("bad input => " + line);
	if (!isValidValue(value)) 
		std::runtime_error("bad input => " + line);
	float number = std::atof(value.c_str());
	if (number < 0)
		throw std::runtime_error("not a positive number");
	if (number > 1000)
		throw std::runtime_error("too large a number.");
	double result = number * getExchangeRate(date);
	std::cout << date << " => " << value << " = " << result << std::endl;
}

void BitcoinExchange::readInput(std::string const &filename)
{
	std::ifstream fin(filename.c_str());
	if (!fin.is_open())
		throw std::runtime_error("Could not open file: " + filename);

	std::string line, date, value;
	std::getline(fin, line);
	if (!checkInputHeader(line))
		throw std::runtime_error("Invalid format header.");

	while (std::getline(fin, line))
	{
		try {
			readInputLine(line);
		} catch (std::exception &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	fin.close();
}

//it->first access key it->second access value
double BitcoinExchange::getExchangeRate(std::string const &date)
{
	std::string target = date;
	std::map<std::string, double>::iterator it;

	it = db.lower_bound(target);

    if (it == db.end()) {
        return --it->second;
    }
	if (it->first == target)
		return it->second;
	if (it != db.begin())
		it--;
	return it->second;
}

// =========== Read dava.csv and create std::map with keys and values ===========

bool checkDataHeader(std::string const &header)
{
	return (header == "date,exchange_rate");
}

bool isValidValue(std::string const &str) {
	if (str.empty())
        return false;
	
	bool 	hasDot = false;
	size_t	pos = 0;

	if (str[pos] == '-' || str[pos] == '+')
		pos++;
	for (; pos < str.length(); pos++) 
	{
		if (str[pos] == '.' && hasDot)
			return false;
		if (str[pos] == '.' && !hasDot)
			hasDot = true;
		if (str[pos] != '.' && !std::isdigit(str[pos]))
			return false;
	}
	return true;
}

void BitcoinExchange::readDataLine(std::string const &line) {
	size_t		comma;
	std::string	date, value;

	comma = line.find(',');
	if (comma == std::string::npos)
		throw (std::runtime_error("bad format => " + line));
	date = line.substr(0, comma);
	value = line.substr(++comma);
	if (!isValidDate(date)) 
		return ;
	if (!isValidValue(value)) 
		return ;
	this->db.insert(std::pair<std::string, double>(date, std::atof(value.c_str())));
}

void BitcoinExchange::readData(std::string const &filename)
{
	std::ifstream fin(filename.c_str());
	if (!fin.is_open())
		throw std::runtime_error("Could not open file: " + filename);

	std::string line, date, value;
	std::getline(fin, line);
	if (!checkDataHeader(line))
		throw std::runtime_error("Invalid format header.");

	while (std::getline(fin, line))
	{
		try {
			readDataLine(line);
		} catch (std::exception &e) {
			throw std::runtime_error("Invalid data inside file");
		}
	}
	fin.close();
	if (db.empty())
		throw std::runtime_error("Database is empty");
}

// =========== date handlers and its utils ===========

bool isCharDigit(char c) {
    return std::isdigit(c) != 0;
}

bool isStringDigit(const std::string& str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
        if (!isCharDigit(*it)) {
            return false;
        }
    }
    return true;
}

std::string getYear(const std::string& date) {
    size_t first = date.find('-');
    if (first == std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    return date.substr(0, first);
}

std::string getMonth(const std::string& date) {
    size_t first = date.find('-');
    if (first == std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    size_t second = date.find('-', ++first);
    if (second == std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    return date.substr(first, second - first);
}

std::string getDay(const std::string& date) {
    size_t first = date.find('-');
    if (first == std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    size_t second = date.find('-', ++first);
    if (second == std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    size_t third = date.find('-', ++second);
    if (third != std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + date);
    }

    return date.substr(second);
}

bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    return false;
}

bool isValidDate(std::string const &date)
{
	std::string syear, smonth, sday;

	try
	{
	    syear = getYear(date);
        smonth = getMonth(date);
        sday = getDay(date);
		if (!isStringDigit(syear) || !isStringDigit(smonth) || !isStringDigit(sday)) {
            throw std::invalid_argument("Error: bad input => " + date);
        }

		int year = std::atoi(syear.c_str());
		int month = std::atoi(smonth.c_str());
		int day = std::atoi(sday.c_str());
		if (year < 0 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
			throw std::invalid_argument("Error: bad input => " + date);
		if (isLeapYear(year) && smonth == FEB && day > 29)
		{
			throw std::invalid_argument("Error: bad input => " + date);
		}
		if (!isLeapYear(year) && smonth == FEB && day > 28)
		{
			throw std::invalid_argument("Error: bad input => " + date);
		}
		if ((smonth == APR || smonth == JUN || smonth == SEP || smonth == NOV) && day > 30)
			throw std::invalid_argument("Error: bad input => " + date);
		return true;
	} catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
		return false;
    }

}

// =========== GET ===========
const std::map<std::string, double>& BitcoinExchange::getDatabase() const {
    return this->db;
}