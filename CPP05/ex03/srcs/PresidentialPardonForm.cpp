/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 07:38:08 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/29 10:07:12 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp" 

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", "", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", target, 25, 5)
{
	std::srand(std::time(0));
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm("PresidentialPardonForm", rhs.getTarget(), 25, 5)
{
	
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	(void)rhs;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSign()){
        throw PresidentialPardonForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeExe()){
        throw PresidentialPardonForm::GradeTooLowException();
    }
	std::cout << "Ah," << this->getTarget() << " my dear friend, you have been pardoned, for in the vast cosmic tapestry of existence, your misadventures have become a delightful spectacle that even the gods couldn't resist chuckling at." << std::endl;
}