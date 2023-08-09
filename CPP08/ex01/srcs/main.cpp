/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:50:05 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/04 07:59:43 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main() {

	try
	{
		std::cout << "\033[1;31m" << "[ PDF TEST ]" << "\033[0m" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[1;33m" << "[ MY TEST ]" << "\033[0m" << std::endl;
	std::cout << "\033[1;34m" << "ADD MORE THAN LIMIT" << "\033[0m" << std::endl;
	try
	{	
		Span elimit(3);
		elimit.addNumber(6);
		elimit.addNumber(8);
		elimit.addNumber(2);
		elimit.addNumber(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[1;34m" << "ADD MORE THAN LIMIT WITH addNumbers" << "\033[0m" << std::endl;
	try
	{	
		Span lAddNumbersTest(3);
		std::list<int> nbs;
		nbs.push_back(4);
		nbs.push_back(5);
		nbs.push_back(7);
		lAddNumbersTest.addNumber(6);
		lAddNumbersTest.addNumber(8);
		lAddNumbersTest.addNumbers(nbs.begin(), nbs.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "\033[1;34m" << "ADD A LOT NUMBERS" << "\033[0m" << std::endl;
	try
	{	
		Span aLotNumbers(10000);

		std::list<int> numbersToAdd;
		srand(time(NULL));
		for(int i = 0; i < 10000; i++)
		{
			int randomNbr = rand() % 100000 + 1;
			numbersToAdd.push_back(randomNbr);
		}
		aLotNumbers.addNumbers(numbersToAdd.begin(), numbersToAdd.end());
		//std::cout << aLotNumbers << std::endl;
		std::cout << "shortest = " << aLotNumbers.shortestSpan() << " longest = " << aLotNumbers.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

