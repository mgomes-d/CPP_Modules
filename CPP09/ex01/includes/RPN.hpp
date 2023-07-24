/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:57:58 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/24 12:10:14 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <climits>
#include <cmath>

class RPN
{
	private:
		std::stack 	_values;
		std::string _args;

	public:
		RPN(void);
		RPN(const std::string &args);
		RPM(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);

		int	calculation(void);
};

#endif