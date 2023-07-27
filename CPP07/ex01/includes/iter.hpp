/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:56:34 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/27 10:35:08 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, std::size_t len, void (*f)(const T &))
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