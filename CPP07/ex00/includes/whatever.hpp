/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 10:25:45 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/10 10:51:53 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
const T &min(T &a, T &b)
{
	return (a < b ? a : b);
}

template<typename T>
const T &max(T &a, T &b)
{
	return (a > b ? a : b);
}

#endif