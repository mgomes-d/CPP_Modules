/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:46:48 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/30 07:53:40 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp" 

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", "", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm("RobotomyRequestForm", rhs.getTarget(), 72, 45)
{
	
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	(void)rhs;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign()){
        throw RobotomyRequestForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeExe()){
        throw RobotomyRequestForm::GradeTooLowException();
    }

	std::cout << "Drdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdrdr, ";
	srand(time(0));

	int successRate = rand() % 100;
	
	if (successRate > 50){
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	}
	else{
		std::cout << "the robotomy failed!" << std::endl;
	}
}