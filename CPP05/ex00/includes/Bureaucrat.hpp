/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 07:42:42 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/27 09:40:51 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:
		const std::string 	_name;
		int				  _grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &rhs);
		Bureaucrat &operator=(const Bureaucrat &rhs);
		~Bureaucrat(void);
	
		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade Too High, range from 150 (highest possible grade) to 1 (lowest possible grade)");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return ("Grade Too Low, range from 150 (highest possible grade) to 1 (lowest possible grade)");
				}
		};
	
		std::string getName(void) const;
		int getGrade(void) const;
		void	addGrade(void);
		void	removeGrade(void);

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif