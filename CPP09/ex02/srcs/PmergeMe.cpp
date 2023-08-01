/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:00:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/01 11:52:01 by mgomes-d         ###   ########.fr       */
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
	while (len < size)
	{
		if (inputArray[len] < 0)
			throw std::runtime_error("Error");
		this->_unsortedVector->push_back(inputArray[len]);
		this->_unsortedList->push_back(inputArray[len]);
		len++;
	}
	std::cout << "Before:  ";
	len = 0;
	while (len < size)
		std::cout << inputArray[len++] << " ";
	std::cout << std::endl;
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

void PmergeMe::_fordJohnsonListSort(int p, int r) 
{
	if (r - p > 5){
		int q = (p + r) / 2;
		this->_fordJohnsonListSort(p, q);
		this->_fordJohnsonListSort(q + 1, r);
		this->_merge(p, q, r);
	}
	else
		this->_InsertionSort(p, r);
	
}

void PmergeMe::_merge(int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	std::list<int>PairA = this->_getListPair(p, q +1);
	std::list<int>PairB = this->_getListPair(q +1, r +1);
	int Ai = 0;
	int Bi = 0;
	int i = 0;

	for (std::list<int>::iterator it = this->_unsortedList->begin(); it != this->_unsortedList->end(); it++){
		if (i < (r - p + 1))
			break;
		if (Bi == n2){
			*it = PairA.front();
			PairA.pop_front();
			Ai++;
		}
		else if (Ai == n1){
			*it = PairB.front();
			PairB.pop_front();
			Bi++;
		}
		else if (PairB.front() > PairA.front()){
			*it = PairA.front();
			PairA.pop_front();
			Ai++;
		}
		else{
			*it = PairB.front();
			PairB.pop_front();
			Bi++;
		}
		i++;
	}
}


std::list<int> PmergeMe::_getListPair(int p, int r)
{
	std::list<int> listed;
	int i = 0;
	for (std::list<int>::iterator it = this->_unsortedList->begin(); it != this->_unsortedList->end(); ++it){
		if (i < p){
			i++;
			continue;
		}
		if (i > r)
			break ;
		listed.push_back(*it);
		i++;
	}
	return (listed);
}

void PmergeMe::_InsertionSort(int p, int r)
{
	int i = 0;
	for (std::list<int>::iterator it = this->_unsortedList->begin(); it != this->_unsortedList->end(); ++it){
		if (i < p){
			i++;
			continue;
		}
		int temp = *it;
		++it;
		
	}
}

void PmergeMe::sort(void)
{
	this->_fordJohnsonListSort(0, this->_unsortedList->size());
}