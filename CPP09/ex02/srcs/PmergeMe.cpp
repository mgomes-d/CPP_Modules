/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:00:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/02 08:17:28 by mgomes-d         ###   ########.fr       */
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

void PmergeMe::_InsertionSort(int p, int q)
{
	// int i = 0;
	// for (std::list<int>::iterator it = this->_unsortedList->begin(); it != this->_unsortedList->end(); ++it){
	// 	if (i < p){
	// 		i++;
	// 		continue;
	// 	}
	// 	if (i > q)
	// 		break ;
	// 	std::list<int>::iterator it2 = it;
	// 	it2++;
	// 	int tempVal = *it2;
	// 	int j = i + 1;
	// 	while (j > p && *it > tempVal){
	// 		std::list<int>::iterator it3 = it2;
	// 		it2--;
	// 		std::swap(it3, it2);
	// 		j--;
	// 	}
	// 	*it = *it2;
	// }
	{
    int i = 0;
    std::list<int>::iterator it = this->_unsortedList->begin();
    std::advance(it, p); // Avance l'itérateur au début de la séquence à trier

    for (; i < q; ++i) {
        int tempVal = *(std::next(it)); // Récupère la valeur de l'élément suivant
        std::list<int>::iterator j = it; // j est l'itérateur courant dans la boucle d'insertion

        while (j != this->_unsortedList->begin() && *(std::prev(j)) > tempVal) {
            // Déplace les éléments plus grands que tempVal vers la droite
            *j = *(std::prev(j));
            --j;
        }
        *j = tempVal; // Insère tempVal à sa position correcte
        ++it;
    }
}
}

void PmergeMe::sort(void)
{
	this->_fordJohnsonListSort(0, this->_unsortedList->size() - 1);
	for (std::list<int>::iterator it = this->_unsortedList->begin(); it != this->_unsortedList->end(); ++it){
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}