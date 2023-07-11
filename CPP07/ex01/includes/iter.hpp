/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:56:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/11 07:53:34 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void iter(T *array, std::size_t len, void (*f)(T &))
{
	for (std::size_t i = 0; i < len; i++){
		f(array[i]);
	}
}
template<typename T>
void	printmsg(T &arg)
{
	std::cout << arg << " ";
}

#endif