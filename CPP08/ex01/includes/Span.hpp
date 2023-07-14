/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 09:50:19 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/14 12:28:50 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <list>
#include <limits>

class Span
{
	private:
		const unsigned int _N;
		std::list<int> _list;
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &rhs);
		Span &operator=(const Span &rhs);
		~Span(void);

		void	addNumber(int nb);
		void	addNumbers(std::list<int>::const_iterator it, std::list<int>::const_iterator ite);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
		const std::list<int> &getList(void) const;
		
		class MaxOfElementsStore: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("You cannot add more numbers!");
				}
		};
		
		class OnlyOneNumberStore: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("There only one number!");
				}
		};
		
		class NoNumberStore: public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("There no number!");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Span &rhs);

#endif