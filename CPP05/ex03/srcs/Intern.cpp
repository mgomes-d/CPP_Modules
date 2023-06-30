/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:15:27 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/30 07:48:59 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{

}

Intern::Intern(const Intern &rhs)
{
	(void) rhs;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return (*this);
}

Intern::~Intern(void)
{

}

AForm *Intern::makeForm(const std::string &form, const std::string &target)
{
	std::string	names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	int i = 0;
	while (i < 3)
	{
		if (names[i].compare(form) == 0)
		{
			break;
		}
		i++;
	}

	switch (i)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			throw Intern::FormParameterNotExist();
	}
}