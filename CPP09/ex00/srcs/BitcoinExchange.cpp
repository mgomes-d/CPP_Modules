/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:23:54 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/20 12:10:56 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(const std::string &infile) : _infile(infile)
{
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	(void)other;////////////
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	(void)other;/////////
	return (*this);////////
}

BitcoinExchange::~BitcoinExchange(void)
{
	
}

void BitcoinExchange::getValue(void)
{
	this->_parseInput();
}

void BitcoinExchange::_parseInput(void)
{
	std::ifstream infile(this->_infile);
	if (!infile)
		throw FileError();
	std::string line;
	int i = 0;
	while (std::getline(infile, line))
	{
		if (i)
			this->_parseInputLine(line);
		i++;
	}
}

void	BitcoinExchange::_parseInputLine(const std::string &line)
{
	std::istringstream iss(line);
	std::string date;
	std::string pipe;
	std::string value;
	iss >> date;
	if (!date.empty())
		return (this->_ParseDate(date));
	iss >> pipe;
	iss >> value;
}

bool BitcoinExchange::_isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::_isValidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->_isLeapYear(year)) {
        daysInMonth[1] = 29;
    }

    if (day > daysInMonth[month - 1]) {
		return false;
    }

    return true;
}

void		BitcoinExchange::_ParseDate(const std::string &date)
{
	std::string yearStr;
	std::string monthStr;
	std::string dayStr;
	
	std::cout << date << std::endl;
	yearStr = date.substr(0, 3);
	if (date[4] != '-' || !this->_isDigits(yearStr)){
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	monthStr = date.substr(5, 2);
	if (date[7] != '-' || !this->_isDigits(monthStr)){
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	dayStr = date.substr(8,2);
	if (date[10] || !this->_isDigits(dayStr)){
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	int 		year = atoi(yearStr.c_str());
	int 		month = atoi(monthStr.c_str());
	int 		day = atoi(dayStr.c_str());
	if (!this->_isValidDate(day, month, year))
		std::cout << "E1rror: bad input => " << date << std::endl;
}

bool BitcoinExchange::_isDigits(const std::string& str) {
    for (size_t i = 0; i < str.length(); i++) {
		char c = str[i];
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}