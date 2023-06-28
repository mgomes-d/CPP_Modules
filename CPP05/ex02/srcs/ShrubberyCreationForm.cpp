/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:11:18 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/28 12:21:00 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const Form &Form)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs)
{
	
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::ofstream outfile(form.getName() + "_shrubbery");
    if (outfile.is_open())
    {
        outfile << "         - - -" << std::endl;
        outfile << "       -        -  -     --    -" << std::endl;
        outfile << "    -                 -         -  -" << std::endl;
        outfile << "                    -" << std::endl;
        outfile << "                   -                --" << std::endl;
        outfile << "   -          -            -              -" << std::endl;
        outfile << "   -            '-,        -               -" << std::endl;
        outfile << "   -              'b      *" << std::endl;
        outfile << "    -              '$    #-                --" << std::endl;
        outfile << "   -    -           $:   #:               -" << std::endl;
        outfile << " --      -  --      *#  @):        -   - -" << std::endl;
        outfile << "              -     :@,@):   ,-**:'   -" << std::endl;
        outfile << "  -      -,         :@@*: --**'      -   -" << std::endl;
        outfile << "           '#o-    -:(@'-@*\"'  -" << std::endl;
        outfile << "   -  -       'bq,--:,@@*'   ,*      -  -" << std::endl;
        outfile << "              ,p$q8,:@)'  -p*'      -" << std::endl;
        outfile << "       -     '  - '@@Pp@@*'    -  -" << std::endl;
        outfile << "        -  - --    Y7'.':     -  -" << std::endl;
        outfile << "                  :@):." << std::endl;
        outfile << "                 .:@:'." << std::endl;
        outfile << "               .::(@:." << std::endl; 
        outfile.close();
    }
}