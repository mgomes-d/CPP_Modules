/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:16:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/28 11:59:30 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class AForm;

class ShrubberyCreationForm : public Aform
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const Form &Form);
		ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
		ShrubberyCreationForm &operator=(void);
		~ShrubberyCreationForm(void);

		virtual void execute(Bureaucrat const & executor) const;
}

#endif