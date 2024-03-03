#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>

#define JAN "01"
#define FEB "02"
#define MAR "03"
#define APR "04"
#define MAY "05"
#define JUN "06"
#define JUL "07"
#define AUG "08"
#define SEP "09"
#define OCT "10"
#define NOV "11"
#define DEC "12"

class BitcoinExchange
{
  public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange(void);

	void readDataLine(std::string const &line);
	void readData(std::string const &filename);
	const std::map<std::string, double>& getDatabase() const;
	void readInput(std::string const &filename);
	void readInputLine(std::string const &line);
	double getExchangeRate(std::string const &date);

  private:
	std::map<std::string, double> db;
};

bool checkDataHeader(std::string const &header);
bool checkInputHeader(std::string const &header);
bool isValidValue(std::string const &str);
bool isCharDigit(char c);
bool isLeapYear(int year);
bool isStringDigit(const std::string& str);
bool isValidDate(std::string const &date);
std::string getDay(const std::string& date);
std::string getMonth(const std::string& date);
std::string getYear(const std::string& date);

#endif