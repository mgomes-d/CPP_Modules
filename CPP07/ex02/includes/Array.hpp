/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 07:56:11 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/11 09:25:23 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
	private:
	unsigned int _size;
	T *_array;
	public:
		Array(void) : _size(0) {};
		Array(unsigned int n) : _size(n)
		{
			if (n > 0){
				this->_array = new T[n];
			}
		};
		Array(const Array &rhs)
		{
			this->_size = 0;
			*this = rhs;
		};
		Array &operator=(const Array &rhs)
		{
			if (this->_size)
				delete [] this->_array;
			this->_size = rhs._size;
			if (this->_size > 0){
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++){
					this->_array[i] = rhs._array[i];
				}
			}
		};
		~Array(void)
		{
			if (this->_size){
				delete [] this ->_array;
			}
		};
		T &operator[](unsigned int i) const
		{
			if (i >= this->_size){
				throw OutOfBoundsException();
			}
			return (this->_array[i]);
		}
		unsigned int size(void) const
		{
			return (this->_size);
		}
		class OutOfBoundsException: public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("{Index is out of bounds}");
				}
		};
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Array<T> &array)
{
	for (unsigned int i = 0; i < array.size(); i++)
	{
		out << array[i] << " ";
	}
	return out;
}

#endif