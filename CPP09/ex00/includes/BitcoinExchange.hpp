/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 10:23:58 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/19 11:37:23 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define ERROR_MSG_OFILE "Error: could not open file."

#include <iostream>
#include <vector>
#include <map>

class BitcoinExchange
{
	private:
		std::string _infile;
		std::map<std::string, int> data
		int		_parseInput(void)
		void	_readInput(void);
	public:
		BitcoinExchange(void);
		BitcoinExchange(const std::string &infile);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange(void);


		class 
};

#endif