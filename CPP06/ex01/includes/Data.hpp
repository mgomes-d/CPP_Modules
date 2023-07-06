/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:25:30 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/07/06 10:52:33 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data
{
	private:
		std::string _name;
		int			_age;

	public:
		Data();
		Data(const std::string &name, int age);
		Data(const Data &rhs);
		Data &operator=(const Data &rhs);
		~Data();
		std::string getName(void) const;
		int getAge(void) const;
};

std::ostream	&operator<<(std::ostream &out, const Data &data);

#endif