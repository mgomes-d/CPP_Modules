/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:47:35 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/03 10:09:35 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &rhs);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter(void);

		// static void _toChar(std::string string param);
		// static void _toInt(std::string string param);
		// static void _toFloat(std::string string param);
		// static void _toDouble(std::string string param);

	public:
		static void convert(std::string param);
};

#endif