/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:48:31 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/27 11:10:33 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Form::Form(void)
{
	
}

Form::Form(const Form &rhs)
{
	
}

Form &Form::operator=(const Form &rhs)
{
	return (*this);
}

Form::Form(const std::string &name, int signExe, int signGrade) : _name(name), _sign(false), _gradeExe(signExe), _gradeSign(signGrade)
{
	if (signExe > 150 || signGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
	else if (signExe < 1 || signGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
}

const std::string Form::getName(void) const
{
	return (this->_name);
}
int Form::getSignGrade(void) const
{
	return (this->_gradeSign);
}

int Form::getSignExe(void) const
{
	return (this->_gradeExe);
}

bool Form::getSign(void) const
{
	return (this->_sign);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade){
		throw Form::GradeTooLowException();
	}
	this->_sign = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form Name: " << form.getName() << ", signed: " << form.getSign() << ", grade to sign it: " << form.getSignGrade()
	<< "grade to execute it: " << form.getSignExe();
}