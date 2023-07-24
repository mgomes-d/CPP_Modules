/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:23:54 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/24 10:52:41 by mgomes-d         ###   ########.fr       */
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
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other){
		this->_infile = other->_infile;
		this->_DataBase = other->_DataBase;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange(void)
{
	
}

void BitcoinExchange::getValue(void)
{
	this->_parseDataBase();
	this->_parseInput();
	
}

void BitcoinExchange::_parseDataBase(void)
{
	std::ifstream infile("data.csv");
	if (!infile)
		throw FileError();
	std::string line;
	std::getline(infile, line);
	if (line.compare("date,exchange_rate") != 0)
		throw DataBaseError();
	while (std::getline(infile, line))
	{
		std::istringstream iss(line);
		std::string date;
		std::string valueStr;
		
		std::getline(iss, date, ',');
		if (this->_ParseDate(date))
			throw DataBaseError();
		std::getline(iss, valueStr, ',');
		if (!this->_isDoubleDigit(valueStr))
			throw DataBaseError();
		std::istringstream iss2(valueStr);
		double value;
		iss2 >> value;
		if (iss2.fail())
			throw DataBaseError();
		this->_DataBase.insert(std::make_pair(date, value));
	}
	
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
		if (!i)
		{
			std::istringstream iss(line);
			std::string date;
			std::string pipe;
			std::string value;
			iss >> date >> pipe >> value;
			if (date.compare("date") != 0 || pipe.compare("|") != 0 || value.compare("value") != 0){
				std::cout << "Error: bad input of date | value => " << line << std::endl;
				continue ;
			}
		}
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
	std::string	valueStr;
	iss >> date;
	if (!date.empty()){
		if (this->_ParseDate(date))
			return ;
	}
	else{
		return ;
	}
	iss >> pipe;
	if (pipe.compare("|") != 0)
		throw FileError();
	iss >> valueStr;
	if (!iss.eof()){
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (iss.fail() || !this->_isDoubleDigit(valueStr)){
		std::cout << "Error: it's not a double." << std::endl;
		return ;
	}
	double value = strtod(valueStr.c_str(), NULL);
	if (value == HUGE_VAL || value == -HUGE_VAL || errno == ERANGE || value > INT_MAX){
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}
	if (value < 0){
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	std::map<std::string, double>::iterator it = this->_DataBase.find(date);
	if (it != this->_DataBase.end()){
		std::cout << it->first << " => " << value << " = " << (it->second * value) << std::endl;
	}
	else{
		it = this->_DataBase.lower_bound(date);
		if (it != this->_DataBase.begin()){
			--it;
			std::cout << it->first << " => " << value << " = " << (it->second * value) << std::endl;
		}
		else{
			std::cout << "Error: The date are not in database." << std::endl;
		}
	}
}

int		BitcoinExchange::_ParseDate(const std::string &date)
{
	std::string yearStr;
	std::string monthStr;
	std::string dayStr;
	
	yearStr = date.substr(0, 4);
	if (date[4] != '-' || !this->_isDigits(yearStr)){
		std::cout << "Error: bad input => " << date << std::endl;
		return(1);
	}
	monthStr = date.substr(5, 2);
	if (date[7] != '-' || !this->_isDigits(monthStr)){
		std::cout << "Error: bad input => " << date << std::endl;
		return(1) ;
	}
	dayStr = date.substr(8,2);
	if (date[10] || !this->_isDigits(dayStr)){
		std::cout << "Error: bad input => " << date << std::endl;
		return(1) ;
	}
	int 		year = atoi(yearStr.c_str());
	int 		month = atoi(monthStr.c_str());
	int 		day = atoi(dayStr.c_str());
	if (!this->_isValidDate(day, month, year))
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return (1);
	}
	return (0);
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

bool BitcoinExchange::_isDoubleDigit(const std::string &param)
{
	bool foundDotD = false;
    bool foundEnd = false;
    for (std::size_t i = 0; i < param.length(); i++){
        char c = param[i];
		if (i == 0 && (c == '+' || c == '-')){
			i++;
			c = param[i];
		}
        if (isdigit(c)){
            if ((i + 1) == param.length()){
                foundEnd = true;
            }
            continue ;
        }
        else if (c == '.'){
            if (foundDotD){
                break ;
            }
            foundDotD = true;
        }
        else {
            break ;
        }
    }
    if (foundEnd){
        return(true);
	}
	return (false);
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
