/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:55:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/08 11:42:12 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <utility>

# include <sstream>
# include <ctime>
# include <cstdlib>
#include <mach/mach_time.h>

class PmergeMe
{
	public:
		PmergeMe(void) {}
		PmergeMe(int *inputArray, std::size_t size);
		PmergeMe( PmergeMe & other )
		{
			(void)other;
		}

		PmergeMe &operator=( PmergeMe & other )
		{
			(void)other;
			return (*this);
		}

		~PmergeMe(void);
		void sort(void);

	private:
		std::list<int> *_unsortedList;
		std::list<int> *_sortedList;
		std::vector<int> *_unsortedVector;
		std::vector<int> *_sortedVector;
		void _fordJohnsonListSort(void);
		std::list< std::pair<int, int> > _getPairL(void);
		bool _comparePairsL(const std::pair<int, int>& a, const std::pair<int, int>& b);
		void _insertionSortPairsL(std::list<std::pair<int, int> >& pairsList);
		void _insertionSortL(std::list<std::pair<int, int> > &pairsList);

		void _fordJohnsonVectorSort(void);
		std::vector< std::pair<int, int> > _getPairV(void);
		bool _comparePairsV(const std::pair<int, int>& a, const std::pair<int, int>& b);
		void _insertionSortPairsV(std::vector<std::pair<int, int> >& pairsvector);
		void _insertionSortV(std::vector<std::pair<int, int> > &pairsvector);

		double _getMicroseconds(void);

};

template<typename T>
bool compare(T &a, T &b)
{
	return (a < b);
}

#endif