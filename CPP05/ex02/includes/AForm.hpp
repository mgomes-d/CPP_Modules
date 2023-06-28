/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 09:50:06 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/28 11:29:36 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool  	  _sign;
		const int _gradeSign;
		const int _gradeExe;
	
	public:
		Form(void);
		Form(const std::string &name, int gradeSign, int gradeExe);
		Form(const Form &rhs);
		Form &operator=(const Form &rhs);
		~Form(void);

		const std::string getName(void) const;
		int getGradeSign(void) const;
		int getGradeExe(void) const;
		bool getSign(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		void execute(Bureaucrat const & executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Exception: Grade Too High");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Exception: Grade Too Low");
				}
		};
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif