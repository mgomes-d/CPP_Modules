/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:15:14 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/30 07:49:25 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &rhs);
		Intern &operator=(const Intern &rhs);
		~Intern(void);

		AForm *makeForm(const std::string &form, const std::string &target);
		class FormParameterNotExist : public std::exception{
			const char *what() const throw()
			{
				return ("the form name passed as parameter doesn't exist");
			} 
		};
};

#endif