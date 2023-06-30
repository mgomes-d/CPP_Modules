/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:47:28 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/29 09:52:17 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

class AForm;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &rhs);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm(void);

		virtual void execute(Bureaucrat const & executor) const;
};

#endif