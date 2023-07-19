/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 09:35:24 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/18 09:08:25 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(): std::stack<T>(){};
		MutantStack<T>(const MutantStack<T> &copy) : std::stack<T>(copy){};
		~MutantStack<T>(){};
		MutantStack<T>	&operator=(const MutantStack &copy){ std::stack<T>::operator=(copy); return (*this); }

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return (std::stack<T>::c.begin()); }
		iterator end() { return (std::stack<T>::c.end()); }
		
		const_iterator begin() const { return (std::stack<T>::c.begin()); }
		const_iterator end() const { return (std::stack<T>::c.end()); }

		reverse_iterator rbegin() { return (std::stack<T>::c.rbegin()); }
		reverse_iterator rend() { return (std::stack<T>::c.rend()); }

		const_reverse_iterator rbegin() const { return (std::stack<T>::c.rbegin()); }
		const_reverse_iterator rend() const { return (std::stack<T>::c.rend()); }
};

#endif