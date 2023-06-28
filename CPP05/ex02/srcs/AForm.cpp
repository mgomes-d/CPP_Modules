/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:48:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/28 11:29:56 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

Form::Form(void) : _name("Default"), _sign(false), _gradeSign(40), _gradeExe(40)
{

}

Form::Form(const Form &rhs) : _name(rhs.getName()), _sign(rhs.getSign()), _gradeSign(rhs.getGradeSign()), _gradeExe(rhs.getGradeExe())
{
	
}

Form::~Form(void)
{
	
}
Form &Form::operator=(const Form &rhs)
{
	this->_sign = rhs.getSign();
	return (*this);
}

Form::Form(const std::string &name, int gradeSign, int gradeExe) : _name(name), _sign(false), _gradeSign(gradeSign), _gradeExe(gradeExe)
{
	if (gradeExe > 150 || gradeSign > 150)
	{
		throw Form::GradeTooLowException();
	}
	else if (gradeExe < 1 || gradeSign < 1)
	{
		throw Form::GradeTooHighException();
	}
}

const std::string Form::getName(void) const
{
	return (this->_name);
}
int Form::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int Form::getGradeExe(void) const
{
	return (this->_gradeExe);
}

bool Form::getSign(void) const
{
	return (this->_sign);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeSign()){
		throw Form::GradeTooLowException();
	}
	this->_sign = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() == )
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form Name: " << form.getName() << ", signed: " << form.getSign() << ", grade to sign it: " << form.getGradeSign()
	<< " grade to execute it: " << form.getGradeExe();
	return (out);
}