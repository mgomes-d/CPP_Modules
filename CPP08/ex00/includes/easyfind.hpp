/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 07:55:10 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/08/04 07:47:31 by mgomes-d         ###   ########.fr       */
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
void	easyfind(T &container, int num)
{
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
		throw ExceptionNumNotFound();
	std::cout << "Number: " << *it << std::endl;
};

#endif