/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:55:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/01 11:21:37 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <utility>

# include <ctime>
# include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe(int *inputArray, std::size_t size);
		~PmergeMe(void);
		void sort(void);

	private:
		std::list<int> *_unsortedList;
		std::list<int> *_sortedList;
		std::vector<int> *_unsortedVector;
		std::vector<int> *_sortedVector;
		void _fordJohnsonListSort(int p, int r);
		static bool _compareIntegers(int a, int b);
		void	_merge(int p, int q, int r);
		void	_InsertionSort(int p, int r);
		std::list<int> _getListPair(int p, int r);
};		


#endif