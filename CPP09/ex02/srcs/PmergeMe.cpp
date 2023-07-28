/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:00:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/28 11:53:21 by mgomes-d         ###   ########.fr       */
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
	std::list<int> copyList = *this->_unsortedList;
	std::list<int> sorted;
	std::list<int> PairA;
	std::list<int> PairB;
	std::size_t i = 0;
	//Pair Seperation
	for (std::list<int>::iterator it = copyList.begin(); it != copyList.end(); ++it)
	{
		if (i % 2 == 0)
			PairB.push_back(*it);
		else
			PairA.push_back(*it);
		i++;
	}
	// Comparation A < B
	std::list<int>::iterator itB = PairB.begin();
	for (std::list<int>::iterator itA = PairA.begin(); itA != PairA.end(); ++itA)
	{
		if (this->_compareIntegers(*itA, *itB)){
			int temp;
			temp = *itA;
			*itA = *itB;
			*itB = temp;
		}
		++itB;
	}
	// insering b3 among a1 et a2
	for (std::list<int>::iterator itA = PairA.begin(); itA != PairA.end(); ++itA)
	{
		//comparing a1 avec a2
		if (std::next(itA) != PairA.end()) {
            if (!this->_compareIntegers(*itA, *std::next(itA))) {
				std::iter_swap(itA, std::next(itA));
            }
			//put e inside
			
		}
	}

	for (std::list<int>::iterator it = PairA.begin(); it != PairA.end(); it++) {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
	for (std::list<int>::iterator it = PairB.begin(); it != PairB.end(); it++) {
        std::cout << *it << " ";
    }
	std::cout << std::endl;
}

void PmergeMe::sort(void)
{
	this->_fordJohnsonListSort();
}