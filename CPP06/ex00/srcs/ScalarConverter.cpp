/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:47:42 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/03 10:07:41 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter &rhs)
{
	(void)rhs;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
	
}

void ScalarConverter::convert(std::string param)
{
	std::cout << param << std::endl;
	for (int i = 0; i < (int)param.size(); i++){
		if (!isprint(param[i])){
			std::cout << "Error: Cannot print" << std::endl;
			return ;
		}
	}
	std::cout << std::endl;
}