/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:47:42 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/30 10:56:17 by mgomes-d         ###   ########.fr       */
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

static void ScalarConverter::convert(std::string string param)
{
	for (int i = 0; i < param.len(); i++)
	{
		if (param)
	}
}