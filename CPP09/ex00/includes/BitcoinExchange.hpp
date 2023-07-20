/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:23:58 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/20 11:45:08 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define ERROR_MSG_OFILE "Error: could not open file."

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		std::string _infile;
		std::map<std::string, int> inputData;
		void	_parseInputLine(const std::string &line);
		void	_parseInput(void);
		void	_ParseDate(const std::string &date);
		bool	_isDigits(const std::string& str);
		bool	_isLeapYear(int year);
		bool	_isValidDate(int day, int month, int year);
		
	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string &infile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange(void);

		void getValue(void);

		class FileError : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return (ERROR_MSG_OFILE);
				}
		};
};

#endif