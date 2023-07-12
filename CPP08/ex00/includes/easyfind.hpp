/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:55:10 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/12 12:02:07 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class ExceptionNumNotFound : public std::exception
{
	public:
		const char *what() const throw ()
		{
			return ("{Index not found}");
		}
};

template <typename T>
void	easyfind(T &list, int num)
{
	typename T::const_iterator it;
	it = std::find(list.begin(), list.end(), num);
	if (it == list.end())
		throw ExceptionNumNotFound();
	std::cout << "Number: " << *it << std::endl;
};

#endif