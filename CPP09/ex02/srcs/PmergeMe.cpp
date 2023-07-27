/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:00:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/27 08:06:15 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int *inputArray, std::size_t size)
{
	std::size_t len = 0;
	this->_unsortedVector = new std::vector<int>();
	this->_sortedVector = new std::vector<int>();
	this->_unsortedList = new std::list<int>();
	this->_sortedList = new std::list<int>();
	std::cout << "Before:  ";
	while (len < size)
	{
		std::cout << inputArray[len] << " ";
		this->_unsortedVector->push_back(inputArray[len]);
		this->_unsortedList->push_back(inputArray[len]);
		len++;
	}
	std::cout << std::endl;
	// // Print the elements of _unsortedVector
    // std::cout << "Unsorted Vector: ";
    // for (std::size_t i = 0; i < _unsortedVector->size(); i++) {
    //     std::cout << (*_unsortedVector)[i] << " ";
    // }
    // std::cout << std::endl;

    // // Print the elements of _unsortedList
    // std::cout << "Unsorted List: ";
    // for (std::list<int>::iterator it = _unsortedList->begin(); it != _unsortedList->end(); it++) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;
}

PmergeMe::~PmergeMe(void)
{
	delete this->_unsortedVector;
	delete this->_sortedVector;
	delete this->_unsortedList;
	delete this->_sortedList;
}

bool PmergeMe::_compareIntegers(int a, int b)
{
    return a < b;
}

void PmergeMe::_fordJohnsonListSort(void) 
{
   // std::list<int> copyList = *this->_unsortedList;

    std::cout << std::endl;
}

void PmergeMe::sort(void)
{
	this->_fordJohnsonListSort();
}