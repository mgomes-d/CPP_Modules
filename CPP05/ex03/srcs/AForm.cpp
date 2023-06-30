/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:48:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/29 10:09:29 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default"), _target(""), _sign(false), _gradeSign(40), _gradeExe(40)
{

}

AForm::AForm(const std::string &name, const std::string &target, int gradeSign, int gradeExe) : _name(name), _target(target), _sign(false), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (gradeExe > 150 || gradeSign > 150)
	{
		throw AForm::GradeTooLowException();
	}
	else if (gradeExe < 1 || gradeSign < 1)
	{
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm(const AForm &rhs) : _name(rhs.getName()), _target(rhs.getTarget()), _sign(rhs.getSign()), _gradeSign(rhs.getGradeSign()), _gradeExe(rhs.getGradeExe())
{
	
}

AForm::~AForm(void)
{
	
}

AForm &AForm::operator=(const AForm &rhs)
{
	this->_sign = rhs.getSign();
	return (*this);
}

const std::string AForm::getName(void) const
{
	return (this->_name);
}

std::string AForm::getTarget(void) const
{
	return (this->_target);
}

int AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int AForm::getGradeExe(void) const
{
	return (this->_gradeExe);
}

bool AForm::getSign(void) const
{
	return (this->_sign);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign()){
		throw AForm::GradeTooLowException();
	}
	this->_sign = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Form Name: " << form.getName() << ", signed: " << form.getSign() << ", grade to sign it: " << form.getGradeSign()
	<< " grade to execute it: " << form.getGradeExe();
	return (out);
}