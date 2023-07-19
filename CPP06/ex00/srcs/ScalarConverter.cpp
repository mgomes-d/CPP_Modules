/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:47:42 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/19 07:31:28 by mgomes-d         ###   ########.fr       */
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
	for (std::size_t i = 0; i < param.length(); i++){
		if (!isprint(param[i])){
			std::cout << "Error: Character non displayable is forbidden" << std::endl;
			return ;
		}
	}
	//char
	if (param.length() == 1 && !isdigit(param[0])){
		return (ScalarConverter::_toChar(param));
	}
	//int
	for (std::size_t i = 0; i < param.length(); i++){
		char c = param[i];
		if (i == 0 && (c == '+' || c == '-')){
			i++;
			c = param[i];
		}
		if (!isdigit(c)){
			break;
		}
		if (i + 1 == param.length()){
			return (ScalarConverter::_toInt(param));
		}
	}
	//float
	bool foundDot = false;
	bool foundSuffix = false;
	for (std::size_t i = 0; i < param.length(); i++){
		char c = param[i];
	
		if (i == 0 && (c == '+' || c == '-')){
			i++;
			c = param[i];
		}
		if (isdigit(c)){
			continue ;
		}
		else if (c == '.'){
			if (foundDot){
				break ;
			}
			foundDot = true;
		}
		else if (i == param.length() - 1 && (c == 'f' | c == 'F')){
			foundSuffix = true;
		}
		else {
			break ;
		}
	}
	if (foundDot && foundSuffix && param[param.length() - 1] == 'f'){
		return (ScalarConverter::_toFloat(param));
	}
	if (param == "-inff" || param == "+inff" || param == "nanf"){
		return ScalarConverter::_toFloat(param);
	}

	//double
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
	if (foundDotD && foundEnd){
		return (ScalarConverter::_toDouble(param));
	}
	if (param == "-inf" || param == "+inf" || param == "nan"){
		return (ScalarConverter::_toDouble(param));
	}
	std::cout << "Impossible convertion" << std::endl << "Supported types are <char>, <int>, <float> and <double>";
	std::cout << std::endl;
}

void ScalarConverter::_toChar(std::string param)
{
	std::cout << "char: '" << param[0] << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(param[0]) << std::endl;
	std::cout << "float: " << static_cast<float>(param[0]) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(param[0]) << ".0" << std::endl;
}

void ScalarConverter::_toInt(std::string param)
{
	std::istringstream iss(param);
	std::istringstream iss2(param);
	int	nb;
	long	lnb;

	iss >> nb;
	iss2 >> lnb;
	if (nb != lnb){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (!isprint(static_cast<char>(nb))){
		std::cout << "char: non displayable" << std::endl;
	}
	else{
		std::cout << "char: " << static_cast<char>(nb) << std::endl;
	}
	std::cout << "int: " << nb << std::endl;
	std::cout << "float: " << static_cast<float>(nb) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(nb) << ".0" << std::endl;
}

void ScalarConverter::_toFloat(std::string param)
{
	if (param == "-inff" || param == "+inff" || param == "nanf"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: " << param << std::endl;
		std::cout << "double: " << param.substr(0, param.length() - 1) << std::endl;
		return ;
	}

	float nb = strtof(param.c_str(), NULL);

	if (nb == HUGE_VALF || nb == -HUGE_VALF || errno == ERANGE){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: overflow" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	if (!isprint(static_cast<char>(nb))){
		std::cout << "char: non displayable" << std::endl;
	}
	else{
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << nb;
	if (static_cast<int>(nb) == nb){
		std::cout << ".0f"; 
	}
	else{
		std::cout << "f";
	}
	std::cout << std::endl;
	std::cout << "double: " << static_cast<double>(nb);
	if (static_cast<int>(nb) == nb){
		std::cout << ".0";
	}
	std::cout << std::endl;
}

void ScalarConverter::_toDouble(std::string param)
{
	if (param == "-inf" || param == "+inf" || param == "nan"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << param << "f" << std::endl;
		std::cout << "double: " << param << std::endl;
		return ;
	}

	double nb = strtod(param.c_str(), NULL);
	if (nb == HUGE_VAL || nb == -HUGE_VAL || errno == ERANGE)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: overflow" << std::endl;
		return;
	}
	if (!isprint(static_cast<char>(nb))){
		std::cout << "char: non displayable" << std::endl;
	}
	else{
		std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
	}
	std::cout << "int: " << static_cast<int>(nb) << std::endl;
	std::cout << "float: " << static_cast<float>(nb);
	if (static_cast<int>(nb) == nb)
		std::cout << ".0f";
	else
		std::cout << "f";
	std::cout << std::endl;
	std::cout << "double: " << nb;
	if (static_cast<int>(nb) == nb){
		std::cout << ".0";
	}
	std::cout << std::endl;
}
