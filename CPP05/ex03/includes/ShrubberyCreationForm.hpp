/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 10:16:40 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/29 10:02:10 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm(void);

		virtual void execute(Bureaucrat const & executor) const;
};

#endif