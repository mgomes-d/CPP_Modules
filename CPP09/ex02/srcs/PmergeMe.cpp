/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:00:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/14 09:31:12 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	this->_unsortedVector = NULL;
	this->_unsortedList = NULL;
	this->_sortedVector = NULL;
	this->_sortedList = NULL;
}

PmergeMe::PmergeMe(PmergeMe &other)
{
	this->_unsortedVector = NULL;
	this->_unsortedList = NULL;
	this->_sortedVector = NULL;
	this->_sortedList = NULL;
	(void)other;
}

PmergeMe &PmergeMe::operator=(PmergeMe &other)
{
	this->_unsortedVector = NULL;
	this->_unsortedList = NULL;
	this->_sortedVector = NULL;
	this->_sortedList = NULL;
	(void)other;
	return (*this);
}

PmergeMe::PmergeMe(int *inputArray, std::size_t size)
{
	std::size_t len = 0;
	this->_unsortedVector = new std::vector<int>();
	this->_sortedVector = new std::vector<int>();
	this->_unsortedList = new std::list<int>();
	this->_sortedList = new std::list<int>();
	while (len < size)
	{
		this->_unsortedVector->push_back(inputArray[len]);
		this->_unsortedList->push_back(inputArray[len]);
		len++;
	}
	if (!len)
		throw std::runtime_error("Error");
	std::cout << "Before:  ";
	len = 0;
	while (len < size)
		std::cout << inputArray[len++] << " ";
	std::cout << std::endl;
}

PmergeMe::~PmergeMe(void)
{
	if (this->_unsortedVector)
		delete this->_unsortedVector;
	if (this->_sortedVector)
		delete this->_sortedVector;
	if (this->_unsortedList)
		delete this->_unsortedList;
	if (this->_sortedList)
		delete this->_sortedList;
}

void PmergeMe::_fordJohnsonListSort(void) 
{
	std::list< std::pair<int, int> > pairsList = this->_getPairL();
	for (std::list< std::pair<int, int> >::iterator it = pairsList.begin(); it != pairsList.end(); ++it)
	{
		if (compare<int>(it->first, it->second) && it->first != -1){
			std::swap(it->first, it->second);
		}
	}
	this->_insertionSortPairsL(pairsList);
	this->_insertionSortL(pairsList);
}

void PmergeMe::_insertionSortL(std::list<std::pair<int, int> > &pairsList)
{
    for (std::list<std::pair<int, int> >::iterator it = pairsList.begin(); it != pairsList.end(); ++it)
    {
        this->_sortedList->push_back(it->second);
		if (it->first != -1)
     	   this->_sortedList->push_back(it->first);
        std::list<int>::iterator j = --this->_sortedList->end();
        while (j != this->_sortedList->begin())
        {
			if (compare<int>(*j, *(--j))){
            	std::swap(*j, *(++j));
        	  	--j;
			}	
        }
    }
}

void PmergeMe::_insertionSortPairsL(std::list<std::pair<int, int> > &pairsList)
{
    for (std::list<std::pair<int, int> >::iterator it = pairsList.begin(); it != pairsList.end(); ++it)
	{
        std::list<std::pair<int, int> >::iterator j = it;
        while (j != pairsList.begin() && j->first != -1 && compare<int>(j->first, (--j)->first))
		{
            std::swap(*j, *(++j));
			--j;
        }
    }
}

std::list< std::pair<int, int> > PmergeMe::_getPairL(void)
{
	std::list< std::pair<int, int> > Pair;
	bool	first = false;
	int temp = 0;
	std::list<int>::iterator ite = this->_unsortedList->end();
	for (std::list<int>::iterator it = this->_unsortedList->begin(); it != ite; ++it)
	{
		if (!first){
			temp = *it;
			first = true;
		} 
		else{
			Pair.push_back(std::make_pair(temp, *it));
			first = false;
			temp = 0;
		}
	}
	if (first)
		Pair.push_back(std::make_pair(-1, temp));
	return (Pair);
}

void PmergeMe::sort(void)
{
	if (!this->_unsortedList || !this->_unsortedVector)
		throw std::runtime_error("Error");
	std::size_t len = this->_unsortedList->size();
	std::clock_t startTime = std::clock();
	this->_fordJohnsonListSort();
	std::clock_t endTime = std::clock();
	double timeList = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
	startTime = std::clock();
	this->_fordJohnsonVectorSort();
	endTime = std::clock();
	double timeVector = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
	std::cout << "After: ";
	for (std::list<int>::iterator it = this->_sortedList->begin(); it != this->_sortedList->end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << len << " elements with std::vector : " << timeVector << " ms" << std::endl;
	std::cout << "Time to process a range of " << len << " elements with std::list : " << timeList << " ms" << std::endl;
}

void PmergeMe::_fordJohnsonVectorSort(void) 
{
	std::vector< std::pair<int, int> > pairsvector = this->_getPairV();
	for (std::vector< std::pair<int, int> >::iterator it = pairsvector.begin(); it != pairsvector.end(); ++it)
	{
		if (compare<int>(it->first, it->second) && it->first != -1){
			std::swap(it->first, it->second);
		}
	}
	this->_insertionSortPairsV(pairsvector);
	this->_insertionSortV(pairsvector);
}

void PmergeMe::_insertionSortV(std::vector<std::pair<int, int> > &pairsvector)
{
    for (std::vector<std::pair<int, int> >::iterator it = pairsvector.begin(); it != pairsvector.end(); ++it)
    {
        this->_sortedVector->push_back(it->second);
		if (it->first != -1)
       		this->_sortedVector->push_back(it->first);
        std::vector<int>::iterator j = --this->_sortedVector->end();
        while (j != this->_sortedVector->begin())
        {
			if (compare<int>(*j, *(--j))){
            	std::swap(*j, *(++j));
        	  	--j;
			}	
        }
    }
}

void PmergeMe::_insertionSortPairsV(std::vector<std::pair<int, int> > &pairsvector)
{
    for (std::vector<std::pair<int, int> >::iterator it = pairsvector.begin(); it != pairsvector.end(); ++it)
	{
        std::vector<std::pair<int, int> >::iterator j = it;
        while (j != pairsvector.begin() && j->first != -1 && compare<int>(j->first, (--j)->first))
		{
            std::swap(*j, *(++j));
			--j;
        }
    }
}

std::vector< std::pair<int, int> > PmergeMe::_getPairV(void)
{
	std::vector< std::pair<int, int> > Pair;
	bool	first = false;
	int temp = 0;
	std::vector<int>::iterator ite = this->_unsortedVector->end();
	for (std::vector<int>::iterator it = this->_unsortedVector->begin(); it != ite; ++it)
	{
		if (!first){
			temp = *it;
			first = true;
		} 
		else{
			Pair.push_back(std::make_pair(temp, *it));
			first = false;
			temp = 0;
		}
	}
	if (first)
		Pair.push_back(std::make_pair(-1, temp));
	return (Pair);
}
