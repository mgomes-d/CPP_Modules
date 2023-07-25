/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:58:56 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/25 10:45:23 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	
}

RPN::RPN(const std::string &args)
{
	this->_args = args;
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other){
		this->_args = other._args;
	}
	return (*this);
}

RPN::~RPN(void)
{

}

int RPN::_isOperation(char c)
{
	return (c == '+' || c == '-' || c == '/'
	 || c == '*');
}

int RPN::_doOperation(char c, int nb1, int nb2)
{
	int result = 0;

    if (c == '+') {
        result = nb1 + nb2;
    }
	else if (c == '-') {
    	result = nb1 - nb2;
    }
	else if (c == '*') {
        result = nb1 * nb2;
    }
	else if (c == '/') {
        if (nb2 != 0) {
            result = nb1 / nb2;
        }
		else {
            std::cout << "Error: cannot divide by 0." << std::endl;
            exit(1);
        }
	}
	return (result);
}

int	RPN::calculation(void)
{
	if (this->_argVerification()){
		std::cout << "Error" << std::endl;
		return (1);
	}

	std::istringstream iss(this->_args);
	std::string arg;
	std::stack<int> myStack;
	int			result = 0;

	while (iss >> arg)
	{
		if (std::isdigit(arg[0]) && !arg[1])
			myStack.push(arg[0] - '0');
		else if (this->_isOperation(arg[0]) && !arg[1]){
			int nb1 = myStack.top();
			myStack.pop();
			int nb2 = 0;
			if (!myStack.empty())
				nb2 = myStack.top();
			else
				break;
			myStack.pop();
			result = this->_doOperation(static_cast<char>(arg[0]), nb2, nb1);
			myStack.push(result);
		}
		else
			return (1);
	}
	std::cout << result << std::endl;
	return (0);
}

int	RPN::_argVerification(void)
{
	std::istringstream iss(this->_args);
	std::string arg;
	int numbers = 0;
	int operators = 0;

	while (iss >> arg)
	{
		if (std::isdigit(arg[0]) && !arg[1])
			numbers++;
		else if (this->_isOperation(arg[0]) && !arg[1]){
			operators++;
		}
		else
			return (1);
	}
	if ((operators + 1) != numbers)
		return (1);
	return (0);
}