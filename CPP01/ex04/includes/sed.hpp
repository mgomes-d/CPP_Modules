/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 08:07:21 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/07 08:59:16 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class File{
	public:
		File(std::string filein, std::string s1, std::string s2);
		~File();
		void remplace(void);
		int	 getContent(void);

	private:
		std::string _content;
		std::string _filein;
		std::string _s1;
		std::string _s2;
	};

#endif