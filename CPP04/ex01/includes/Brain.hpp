/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgomes-d <mgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 08:24:04 by mgomes-d          #+#    #+#             */
/*   Updated: 2023/06/20 09:50:08 by mgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{

public:
	Brain(void);
	Brain(const Brain &rhs);
	Brain &operator=(const Brain &rhs);
	~Brain(void);

protected:
	std::string _ideas[100];
};

#endif