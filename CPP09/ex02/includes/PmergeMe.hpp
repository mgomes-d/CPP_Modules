/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:55:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/26 10:53:19 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

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
		void _fordJohnsonListSort(void);
		static bool _compareIntegers(int a, int b);
};

#endif