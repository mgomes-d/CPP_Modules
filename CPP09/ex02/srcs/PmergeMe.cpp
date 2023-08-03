/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:00:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/03 12:09:07 by mgomes-d         ###   ########.fr       */
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
	delete this->_unsortedVector;
	delete this->_sortedVector;
	delete this->_unsortedList;
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
	std::size_t len = this->_unsortedList->size();
	double before = this->_getMicroseconds();
	this->_fordJohnsonListSort();
	double timeList = this->_getMicroseconds() - before;
	before = this->_getMicroseconds();
	this->_fordJohnsonVectorSort();
	double timeVector = this->_getMicroseconds() - before;
	std::cout << "After: ";
	for (std::list<int>::iterator it = this->_sortedList->begin(); it != this->_sortedList->end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << len << " elements with std::vector : " << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << len << " elements with std::list : " << timeList << " us" << std::endl;
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

double PmergeMe::_getMicroseconds(void)
{
    static mach_timebase_info_data_t timebaseInfo;
    if (timebaseInfo.denom == 0) {
        mach_timebase_info(&timebaseInfo);
    }
    uint64_t currentTime = mach_absolute_time();
    uint64_t nanoseconds = currentTime * timebaseInfo.numer / timebaseInfo.denom;
    return static_cast<double>(nanoseconds) / 1000.0;
}