/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:50:06 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/30 07:37:08 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		std::string _target;
		bool  	  _sign;
		const int _gradeSign;
		const int _gradeExe;
	
	public:
		AForm(void);
		AForm(const std::string &name, const std::string &target, int gradeSign, int gradeExe);
		AForm(const AForm &rhs);
		AForm &operator=(const AForm &rhs);
		virtual ~AForm(void);

		const std::string getName(void) const;
		std::string getTarget(void) const;
		int getGradeSign(void) const;
		int getGradeExe(void) const;
		bool getSign(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade Too High");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade Too Low");
				}
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("This form is not signed");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif