/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 10:57:58 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/25 10:25:21 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <climits>
#include <cmath>
#include <sstream>
#include <cctype>

class RPN
{
	private:
		std::string _args;
		int			_isOperation(char c);
		int			_argVerification(void);
		int	 		_doOperation(char c, int nb1, int nb2);

	public:
		RPN(void);
		RPN(const std::string &args);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);

		int	calculation(void);
};

#endif