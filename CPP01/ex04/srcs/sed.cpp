/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:12:05 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/06 10:56:02 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

File::File(std::string filein, std::string s1, std::string s2) : _filein(filein), _s1(s1), _s2(s2)
{
	return ;
}

File::~File(void)
{
	return ;
}

int File::getContent(void)
{
	std::ifstream	ifs(this->_filein);
	
	if (!ifs.is_open()){
		std::cout << "Error opening file" << std::endl;
		return (1);
	}

	std::string	temp;
	std::string content;

	while(std::getline(ifs, temp)){
		content += temp;
		if (!ifs.eof()){
			content += "\n";
		}
	}
	ifs.close();
	this->_content = content;
	return (0);
}

void File::remplace(void)
{
	std::string newText = this->_content;
	size_t	position = newText.find(this->_s1);
	while (position != std::string::npos) {
		newText = newText.substr(0, position) + _s2 + newText.substr(position + _s1.length());
        position = newText.find(this->_s1, position + this->_s1.length());
    }
	this->_content = newText;
	std::ofstream outfile(this->_filein + ".remplace");
	if (!outfile.is_open()){
		std::cout << "Error creating outfile" << std::endl;
		return ;
	}
	outfile << this->_content;
	outfile.close();
	return ;
}
